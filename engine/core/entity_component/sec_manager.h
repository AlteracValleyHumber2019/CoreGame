#ifndef SEC_MANAGER_H
#define SEC_MANAGER_H

#include "../event_attorney.h"
#include "game_object_manager.h"
#include "component_manager.h"

namespace pav
{
	// Forward declare
	class GameObjectManager;
	class ComponentManager;

	class IGameObjectBase;
	class IComponentBase;

	/**
	 * \class	SECManager
	 *
	 * \brief	Manager for the entity component system.
	 *
	 * \author	Jaymie
	 * \date	2/12/2019
	 */
	class SECManager
	{
	private:
		std::unique_ptr<GameObjectManager> game_object_manager_;
		std::unique_ptr<ComponentManager> component_manager_;

		EventAttorney* event_attorny_;

	public:
		SECManager();

		/**
		 * \fn	template <typename Type> inline IGameObjectBase* SECManager::AddGameObject(std::string&& name);
		 *
		 * \brief	Adds a IGameObject object
		 *
		 * \tparam	Type	Type of the IGameObject subtype.
		 * \param [in]	name	The name.
		 *
		 * \returns	Null if it fails, else a pointer to an IGameObjectBase.
		 */
		template <typename Type>
		inline IGameObjectBase* AddGameObject(std::string&& name);

		/**
		 * \fn	template <typename Type> inline IGameObjectBase* SECManager::AddGameObject(std::string&& name, IGameObjectBase* parent);
		 *
		 * \brief	Adds a IGameObject to a parent IGameObject object
		 *
		 * \tparam	Type	Type of the IGameObject subtype.
		 * \param [in]	name  	The name.
		 * \param [in]	parent	If non-null, the parent.
		 *
		 * \returns	Null if it fails, else a pointer to an IGameObjectBase.
		 */
		template <typename Type>
		inline IGameObjectBase* AddGameObject(std::string&& name, IGameObjectBase* parent);

		/**
		 * \fn	void SECManager::RemoveGameObject(std::string&& name);
		 *
		 * \brief	Removes a IGameObject based object by its name
		 *
		 * \author	Jaymie
		 * \date	2/12/2019
		 *
		 * \param [in]	name	The name.
		 */
		void RemoveGameObject(std::string&& name);

		/**
		 * \fn	template <typename C, typename ...Args> inline IComponentBase* SECManager::AddComponent(Args&& ...args);
		 *
		 * \brief	Adds a component
		 *
		 * \tparam	C	   	Type of the component.
		 * \tparam	...Args	Type of the constructor arguments.
		 * \param [in]	...args	The component constructor arguments.
		 *
		 * \returns	Null if it fails, else a pointer to a pav::IComponentBase.
		 */
		template <typename C, typename ...Args>
		inline IComponentBase* AddComponent(Args&& ...args);

		/**
		 * \fn	template <typename C> inline void SECManager::RemoveComponent(const size_t index = 0);
		 *
		 * \brief	Removes the component with the type C
		 *
		 * \tparam	C	Type of the c.
		 * \param	index	(Optional) Zero-based index of the.
		 */
		template <typename C>
		inline void RemoveComponent(const size_t index = 0);

		/**
		 * \fn	void SECManager::Update(float delta_time);
		 *
		 * \brief	Updates all objects
		 *
		 * \author	Jaymie
		 * \date	2/12/2019
		 *
		 * \param	delta_time	The delta time.
		 */
		void Update(float delta_time);

		/**
		 * \fn	void SECManager::SetupEngineEvents(EventAttorney* event_attorney);
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

	template <typename Type>
	IGameObjectBase* SECManager::AddGameObject(std::string&& name)
	{
		return game_object_manager_->AddGameObject(std::move(name));
	}

	template <typename Type>
	IGameObjectBase* SECManager::AddGameObject(std::string&& name, IGameObjectBase* parent)
	{
		return game_object_manager_->AddGameObject(std::move(name), parent);
	}

	template <typename C, typename ...Args>
	IComponentBase* SECManager::AddComponent(Args&& ...args)
	{
	}

	template <typename C>
	void SECManager::RemoveComponent(const size_t index)
	{
	}

}

#endif // SEC_MANAGER_H