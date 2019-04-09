#ifndef MANAGER_FACTORY_H
#define MANAGER_FACTORY_H

#include "scene_manager.h"
#include "ui_manager.h"
#include "window_manager.h"
#include "event_manager.h"
#include "render_manager.h"

namespace pav
{
	/**
	 * \class	ManagerFactory
	 *
	 * \brief	A factory used to create api dependent managers based on pre compiled settings
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class ManagerFactory
	{
	public:
		static std::unique_ptr<SceneManager> CreateSceneManager();
		static std::unique_ptr<UIManager> CreateUIManager();
		static std::unique_ptr<WindowManager> CreateWindowManagerManager();
		static std::unique_ptr<EventManager> CreateEventManager();
		static std::unique_ptr<RenderManager> CreateRenderManager();
	};
}

#endif // MANAGER_FACTORY_H
