#include "pav_pch.h"
#include "resource.h"

pav::IResourceBase::IResourceBase(const unsigned int guid) :
	guid_(guid)
{
}

unsigned int pav::IResourceBase::GetGUID() const
{
	return guid_;
}
