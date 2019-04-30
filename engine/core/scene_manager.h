#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "i_manager.h"
#include "i_scene.h"
#include "event_attorney.h"
#include "util/wrappers/type_wrappers.h"

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
		WindowType* current_window_ptr_;

		std::unordered_map<std::string, std::unique_ptr<IScene>> scenes_;
		IScene* current_scene_;

		EventAttorney* event_attorney_;

	public:
		void Initialize() override;
		void End() override;
		void Update(const float delta_time) override;

		/**
		 * \fn	IScene* SceneManager::AddScene(std::string&& Name, std::unique_ptr<IScene>&& scene);
		 *
		 * \brief	Adds a scene
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param [in]	Name 	The name of the scene.
		 * \param [in]	scene	The scene.
		 *
		 * \returns	Null if it fails, else a pointer to a Scene.
		 */
		IScene* AddScene(std::string&& Name, std::unique_ptr<IScene>&& scene);

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
		IScene* GetScene(std::string&& Name);

		/**
		 * \fn	void SceneManager::RemoveScene(std::string&& Name);
		 *
		 * \brief	Remove a scene
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param [in]	Name	The name of the scene.
		 */
		void RemoveScene(std::string&& Name);

		/**
		 * \fn	void SceneManager::SwitchScene(std::string&& Name);
		 *
		 * \brief	Switch the current scene to a new scene
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \param [in]	Name	The name.
		 */
		void SwitchScene(std::string&& Name);

		void SetupEngineEvents(EventAttorney* event_attorney);

		void SetWindowPtr(WindowType* win);

		IScene* GetCurrentScene();
	};
}

#endif // SCENEMANAGER_H
