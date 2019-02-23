#include "pav_pch.h"
#include "i_component.h"

#include "i_game_object.h"

pav::IComponentBase::IComponentBase(const unsigned int guid, const unsigned int order, IGameObjectBase* owner) :
	guid_(guid),
	order_(order),
	owner_(owner)
{
}

pav::IGameObjectBase* pav::IComponentBase::GetOwner()
{
	return owner_;
}

void pav::IComponentBase::SetActive(const bool active)
{
	is_active_ = active;
}

void pav::IComponentBase::SetIgnoreAutoUpdate(const bool ignore)
{
	ignore_auto_update_ = ignore;
}
