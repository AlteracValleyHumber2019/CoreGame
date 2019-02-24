#ifndef GAME_OBJECT_MANAGER_H
#define GAME_OBJECT_MANAGER_H

#include "i_game_object.h"

namespace pav
{
	/**
	 * \class	GameObjectManager
	 *
	 * \brief	Manager for IGameObject based objects.
	 *
	 * \author	Jaymie
	 * \date	2/12/2019
	 */
	class GameObjectManager
	{
	private:
		std::unordered_map<std::string, std::unique_ptr<pav::IGameObjectBase>> game_objects_;

		EventAttorney* event_attorney_;

	public:

		/**
		 * \fn	template <typename Type> inline IGameObjectBase* GameObjectManager::AddGameObject(std::string&& name)
		 *
		 * \brief	Adds a IGameObject object
		 *
		 * \tparam	Type	Type of the IGameObject subtype.
		 * \param [in]	name	The name.
		 *
		 * \returns	Null if it fails, else a pointer to an IGameObjectBase.
		 */
		template <typename Type>
		inline IGameObjectBase* AddGameObject(std::string&& name)
		{
			// Check if we already have a GameObject with same name
			if (game_objects_.find(name) == game_objects_.end())
			{
				std::string temp_name(name);
				game_objects_.insert(std::make_pair(temp_name, std::make_unique<Type>(std::move(temp_name), 0, 0))); // #TODO: Add GameObject GUID and order

				// GameObject begin logic
				auto go = game_objects_.at(std::move(name)).get();
				go->SetupEngineEvents(event_attorney_);
				go->Begin();

				return go;
			}

			return nullptr;
		}

		/**
		 * \fn	template <typename Type> inline IGameObjectBase* GameObjectManager::AddGameObject(std::string&& name, IGameObjectBase* parent)
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
		inline IGameObjectBase* AddGameObject(std::string&& name, IGameObjectBase* parent)
		{
			// Check if we already have a GameObject with same name, and parent is not NULL
			if (game_objects_.find(name) == game_objects_.end() && parent != nullptr)
			{
				game_objects_.insert(std::make_pair(name, std::make_unique<Type>()));

				// GameObject begin logic
				auto go = game_objects_.at(name);
				parent->children_.insert(std::make_pair(std::move(name), go));
				go->parent_ = parent;

				go->Begin();
				go->SetupEngineEvents(event_attorney_);

				return go;
			}

			return nullptr;
		}

		/**
		 * \fn	void GameObjectManager::RemoveGameObject(std::string&& name);
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
		 * \fn	void GameObjectManager::Update(float delta_time);
		 *
		 * \brief	Updates all IGameObjectBased objects
		 *
		 * \author	Jaymie
		 * \date	2/12/2019
		 *
		 * \param	delta_time	The delta time.
		 */
		void Update(float delta_time);

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

#endif // GAME_OBJECT_MANAGER_H

