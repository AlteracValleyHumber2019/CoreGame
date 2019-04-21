#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "i_component.h"
#include "../util/guid.h"

namespace pav
{
	class IGameObjectBase;

	using ComponentElementType = std::vector<std::unique_ptr<IComponentBase>>;

	/**
	 * \class	ComponentManager
	 *
	 * \brief	Manager for components.
	 *
	 * \author	Jaymie
	 * \date	2/12/2019
	 */
	class ComponentManager
	{
	private:
		std::unordered_map<unsigned int, ComponentElementType> components_;

		EventAttorney* event_attorney_;

	public:

		/**
		 * \fn	template <typename C, typename ...Args> inline IComponentBase* ComponentManager::AddComponent(IGameObjectBase* owner, Args&& ...args);
		 *
		 * \brief	Adds a component
		 *
		 * \tparam	C	   	Type of the component.
		 * \tparam	...Args	Type of the constructor arguments.
		 * \param [in,out]	owner  	If non-null, the owner.
		 * \param [in]	  	...args	The component constructor arguments.
		 *
		 * \returns	Null if it fails, else a pointer to a pav::IComponentBase.
		 */
		template <typename C, typename ...Args>
		inline IComponentBase* AddComponent(IGameObjectBase* owner, Args&& ...args);

		/**
		 * \fn	template <typename C> inline void ComponentManager::RemoveComponent(const size_t index = 0)
		 *
		 * \brief	Removes the component with the type C
		 *
		 * \tparam	C	Type of the c.
		 * \param	index	(Optional) Zero-based index of the.
		 */
		template <typename C>
		inline void RemoveComponent(const size_t index = 0)
		{
			// Get id
			unsigned int id = GUID<IComponentBase>::GetID<C>();

			// If we have Component of type C
			if (components_.find(id) != components_.end())
			{
				auto& std_vec = components_.at(id);

				// If index is not dumb
				if (index < std_vec.size())
				{
					std_vec.at(index)->End(); // Calling component end logic
					std_vec.erase(std_vec.begin() + index);
				}
			}
		}

		template <typename C>
		inline IComponentBase* GetComponent(const size_t index = 0);

		/**
		 * \fn	void GameObjectManager::SetupEngineEvents(EventAttorney* event_attorney);
		 *
		 * \brief	Sets up the engine events
		 *
		 * \author	Jaymie
		 * \date	2/12/2019
		 *
		 * \param [in]	event_attorney	If non-null, the event attorney.
		 */
		void SetupEngineEvents(EventAttorney* event_attorney);
	};
}

#include "i_game_object.h"

template <typename C, typename... Args>
pav::IComponentBase* pav::ComponentManager::AddComponent(IGameObjectBase* owner, Args&& ...args)
{
	// Get id
	unsigned int id = pav::GUID<IComponentBase>::GetID<C>();

	// Check if we already have a Component with same type
	if (components_.find(id) == components_.end())
	{
		components_.insert(std::make_pair(id, std::vector<std::unique_ptr<IComponentBase>>()));
	}

	// Adding component
	auto temp_vec = &components_.at(id);

	temp_vec->emplace_back(std::make_unique<C>(owner, std::forward<Args>(args)...));
	IComponentBase* comp = temp_vec->at(temp_vec->size() - 1).get();
	comp->SetupEngineEvents(event_attorney_);
	comp->Begin(); // Calling component begin logic

	return comp;
}

template <typename C>
pav::IComponentBase* pav::ComponentManager::GetComponent(const size_t index /*= 0*/)
{
	// Get id
	unsigned int id = GUID<IComponentBase>::GetID<C>();

	// If we have Component of type C
	if (components_.find(id) != components_.end())
	{
		auto& std_vec = components_.at(id);

		// If index is not dumb
		if (index < std_vec.size())
		{
			return std_vec.at(index).get();
		}
	}
}

#endif // COMPONENT_MANAGER_H