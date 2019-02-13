#include "pav_pch.h"

#include "i_game_object.h"

#include "../util/guid.h"
#include "i_component.h"

pav::IGameObjectBase::IGameObjectBase(std::string&& name, const unsigned int guid, const unsigned int order) :
	name_(name),
	guid_(guid),
	parent_(nullptr),
	order_(order)
{
}

void pav::IGameObjectBase::Update(const float delta_time)
{
	for (auto comp_vec : components_)
	{
		for (auto comp : comp_vec.second)
		{
			comp->Update(delta_time);
		}
	}
}

template <typename CRTP>
pav::IGameObject<CRTP>::IGameObject(std::string&& name, const unsigned int order) :
	IGameObjectBase(std::move(name), pav::GUID<IGameObjectBase>::GetID<CRTP>(), order)
{
}