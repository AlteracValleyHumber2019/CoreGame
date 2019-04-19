#include "pav_pch.h"
#include "i_game_object.h"

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
	// For each type of components
	for (auto comp_vec : components_)
	{
		// For each component of a type
		for (auto comp : comp_vec.second)
		{
			comp->Update(delta_time);
		}
	}
}
