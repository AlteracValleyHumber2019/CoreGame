#ifndef RESOURCE_POOL_H
#define RESOURCE_POOL_H

#include "resource.h"

#include "../util/guid.h"

namespace pav
{
	/**
	 * \class	ResourcePool
	 *
	 * \brief	A resource pool.
	 *
	 * \author	Jaymie
	 * \date	2/19/2019
	 */
	class ResourcePool
	{
	private:
		std::unordered_map<unsigned int, std::unordered_map<std::string, std::shared_ptr<IResourceBase>>> resource_map_;

	public:

		/**
		 * \fn	void ResourcePool::AddToPool(std::string&& name, std::shared_ptr<IResourceBase>&& resource);
		 *
		 * \brief	Add a temporary resource to the manager pool.
		 * 			
		 * This function will move the parameter resource and therefore should only be used with
		 * rvalues or values client do not wish to continue using in the near future lines of
		 * code. If you wish to use resource after adding it to the resource manager pool please
		 * refer to the function \ref void AddToPool(std::string&& name, const std::shared_ptr<IResourceBase>& resource)
		 *
		 * \author	Jaymie
		 * \date	2/21/2019
		 *
		 * \param [in]	name		The name.
		 * \param [in]	resource	The resource.
		 */
		void AddToPool(std::string&& name, std::shared_ptr<IResourceBase>&& resource);

		/**
		 * \fn	void ResourcePool::AddToPool(std::string&& name, const std::shared_ptr<IResourceBase>& resource);
		 *
		 * \brief	Add a resource to the manager pool.
		 * 			
		 * This function copies the resource parameter and increments its reference count by
		 * one. Therefore it should only be used on lvalues. For adding a temporary resource to
		 * the manager pool please refer to \ref void void AddToPool(std::string&& name, std::shared_ptr<IResourceBase>&& resource)
		 *
		 * \author	Jaymie
		 * \date	2/21/2019
		 *
		 * \param [in]	name		The name.
		 * \param 	  	resource	The resource.
		 */
		void AddToPool(std::string&& name, const std::shared_ptr<IResourceBase>& resource);

		/**
		 * \fn	template <typename ResourceType> inline std::shared_ptr<ResourceType> ResourcePool::GetSharedResource(std::string&& name)
		 *
		 * \brief	Gets the shared resource of type ResourceType
		 * 			
		 * Shared resource returns a shared pointer to the resource and therefore will
		 * increments the resource count.
		 *
		 * \tparam	ResourceType	Type of the resource wrapper.
		 * \param [in]	name	The name.
		 *
		 * \returns	The shared resource if succeed, NULL otherwise.
		 */
		template <typename ResourceType>
		inline std::shared_ptr<ResourceType> GetSharedResource(std::string&& name)
		{
			auto id = pav::GUID<IResourceBase>::GetID<ResourceType>(); // Gets the resource type id

			// Get secondary map
			auto second_map = resource_map_.at(id);

			if (second_map.find(name) != second_map.end())
			{
				return second_map.at(std::forward<std::string>(name));
			}

			return nullptr;
		}

		/**
		 * \fn	template <typename ResourceType> inline std::weak_ptr<ResourceType> ResourcePool::GetWeakResource(std::string&& name)
		 *
		 * \brief	Gets the weak resource of type ResourceType
		 * 			
		 * Weak resource returns a weak pointer to the resource and therefore will not increase the resource count.
		 * However, you should always check the validity of the resource before using one.
		 *
		 * \tparam	ResourceType	Type of the resource wrapper.
		 * \param [in]	name	The name.
		 *
		 * \returns	The weak resource if succeed, NULL otherwise.
		 */
		template <typename ResourceType>
		inline std::weak_ptr<ResourceType> GetWeakResource(std::string&& name)
		{
			auto id = pav::GUID<IResourceBase>::GetID<ResourceType>(); // Gets the resource type id

			// Get secondary map
			auto second_map = resource_map_.at(id);

			if (second_map.find(name) != second_map.end())
			{
				return second_map.at(std::forward<std::string>(name));
			}

			return nullptr;
		}
	};
}

#endif // RESOURCE_POOL_H
