#include "pav_pch.h"
#include "resource.h"

#include "../util/guid.h"

pav::IResourceBase::IResourceBase(const unsigned int guid) :
	guid_(guid)
{
}

unsigned int pav::IResourceBase::GetGUID() const
{
	return guid_;
}

template <typename CRTP, typename Data, typename ...LoadArgs>
pav::Resource<CRTP, Data, LoadArgs...>::Resource() :
	IResourceBase(pav::GUID<IResourceBase>::GetID<CRTP>())
{
}
