#ifndef ENGINE_H
#define ENGINE_H

#include "scene_manager.h"
#include "window_manager.h"
#include "event_manager.h"
#include "render_manager.h"

namespace pav
{
	/**
	 * \class	Engine
	 *
	 * \brief	Engine class for Project Alterac Valley
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class Engine final
	{
	private:
		bool running_;

		WindowInfo window_info_;

		std::unique_ptr<EventAttorney> event_attorney_;

		/**
		 * \fn	void Engine::EndEngine();
		 *
		 * \brief	Called automatically during engine shutdown
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 */
		void EndEngine();

	public:
		std::unique_ptr<SceneManager> scene_manager;
		std::unique_ptr<WindowManager> window_manager;
		std::unique_ptr<EventManager> event_manager;
		std::unique_ptr<RenderManager> render_manager;

		Engine();

		/**
		 * \fn	void final::InitEngine();
		 *
		 * \brief	Initializes the engine
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 */
		void InitEngine();

		/**
		 * \fn	void Engine::StartEngine();
		 *
		 * \brief	This function will invoke the main game loop.
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 */
		void StartEngine();

		/**
		 * \fn	void Engine::Update(float delta_time);
		 *
		 * \brief	Update function that gets called every game loop
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param	delta_time	The delta time.
		 */
		void Update(const float delta_time);

		void SetWindowInfo(WindowInfo&& window_info);
	};
}

#endif // ENGINE_H
