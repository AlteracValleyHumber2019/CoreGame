#include "pav_pch.h"
#include "resource_pool.h"

void pav::ResourcePool::AddToPool(std::string&& name, std::shared_ptr<IResourceBase>&& resource)
{
	// Get secondary map
	auto second_map = resource_map_.at(resource->GetGUID());

	// Check if the map has resource with same name
	if (second_map.find(name) == second_map.end())
	{
		// No same name, thus can insert
		second_map.insert(std::make_pair(std::forward<std::string>(name), std::move(resource)));
	}
}

void pav::ResourcePool::AddToPool(std::string&& name, const std::shared_ptr<IResourceBase>& resource)
{
	// Get secondary map
	auto second_map = resource_map_.at(resource->GetGUID());

	// Check if the map has resource with same name
	if (second_map.find(name) == second_map.end())
	{
		// No same name, thus can insert
		second_map.insert(std::make_pair(std::forward<std::string>(name), resource));
	}
}
