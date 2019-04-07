#include "pav_pch.h"
#include "model_resource.h"

pav::Model pav::ModelResource::GetData()
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool pav::ModelResource::Load(std::string&& args, ModelLoadInfo&& info)
{
	return true;
}

pav::Model pav::ModelResource::GetData() const
{
	throw std::logic_error("The method or operation is not implemented.");
}
