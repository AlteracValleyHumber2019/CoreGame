#ifndef ENGINE_H
#define ENGINE_H

#include "scene_manager.h"
#include "window_manager.h"
#include "event_manager.h"
#include "render_manager.h"
#include "SDLCamera.h"
//#include "graphics\createModel.h"

/** \namespace pav
 *  \brief Project Alterac Valley namespace
 */
namespace pav
{
	/**
	 * \class	Engine
	 *
	 * \brief	Engine class for Project Alterac Valley
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 * 			
	 * \section ex1 Creating an engine entry point with a standard c++ main
	 * 			To write your game with Project Alterac Valley, you must create a Engine on the
	 * 			heap inside your main function. Once the engine object is created you now need to
	 * 			create a engine window using the function \ref SetWindowInfo(WindowInfo&&)
	 * 			Lastly you need to call \ref InitEngine() to initialize engine sub systems.
	 * 			from here on you may add your custom scenes into your game(refer to \ref IScene)
	 * \snippet example_main.cpp ExampleMain entry point
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
		//create a unique camera instance[BP]
		std::unique_ptr<SDLCamera> camera;
		//create a unique Capsule Model

		Engine();

		/**
		 * \fn	void Engine::InitEngine();
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

		/**
		 * \fn	void Engine::SetWindowInfo(WindowInfo&& window_info);
		 *
		 * \brief	Sets window information for the engine
		 *
		 * \author	Jaymie
		 * \date	2/21/2019
		 *
		 * \param [in]	window_info	WindowInfo struct describing the window.
		 */
		void SetWindowInfo(WindowInfo&& window_info);
	};
}

#endif // ENGINE_H
