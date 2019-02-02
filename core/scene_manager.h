#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "i_manager.h"
#include "scene.h"

namespace pav
{
	/**
	 * \class	SceneManager
	 *
	 * \brief	Manager class for scenes.
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class SceneManager : public IManager
	{
	private:
		std::unordered_map<std::string, std::unique_ptr<Scene>> scenes_;

	public:
		void Initialize() override;
		void End() override;
		void Update(const float delta_time) override;

		/**
		 * \fn	Scene* SceneManager::AddScene(std::string&& Name);
		 *
		 * \brief	Adds a scene
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param [in]	Name	The name of the scene.
		 *
		 * \returns	Null if it fails, else a pointer to a Scene.
		 */
		Scene* AddScene(std::string&& Name);

		/**
		 * \fn	Scene* SceneManager::GetScene(std::string&& Name);
		 *
		 * \brief	Gets a scene
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param [in]	Name	The name of the scene.
		 *
		 * \returns	Null if it fails, else a pointer to scene.
		 */
		Scene* GetScene(std::string&& Name);

		/**
		 * \fn	Scene* SceneManager::RemoveScene(std::string&& Name);
		 *
		 * \brief	Remove a scene
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param [in]	Name	The name of the scene.
		 *
		 * \returns	Null if it fails, else a pointer to a Scene.
		 */
		Scene* RemoveScene(std::string&& Name);
	};
}

#endif // SCENEMANAGER_H
