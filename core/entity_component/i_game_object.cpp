#include "pav_pch.h"

#include "i_game_object.h"

#include "../util/guid.h"

pav::IGameObjectBase::IGameObjectBase(std::string&& name, const unsigned int guid, unsigned int order) :
	name_(name),
	guid_(guid),
	order_(order)
{
}

template <typename CRTP>
pav::IGameObject<CRTP>::IGameObject(std::string&& name, const unsigned int order) :
	IGameObjectBase(std::move(name), pav::GUID<IGameObjectBase>::GetID<CRTP>(), order)
{
}