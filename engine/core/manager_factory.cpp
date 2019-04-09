#include "pav_pch.h"

#include "manager_factory.h"
#include "dependent/sdl/gl_sdl_window.h"
#include "dependent/sdl/sdl_event_manager.h"
#include "dependent/sdl/gl_sdl_render_manager.h"

std::unique_ptr<pav::SceneManager> pav::ManagerFactory::CreateSceneManager()
{
	return std::make_unique<SceneManager>();
}

std::unique_ptr<pav::UIManager> pav::ManagerFactory::CreateUIManager()
{
	return std::make_unique<UIManager>();
}

std::unique_ptr<pav::WindowManager> pav::ManagerFactory::CreateWindowManagerManager()
{
#ifdef ENGINE_TYPE_GL_SDL
	return std::make_unique<WindowManager>(std::make_unique<GLSDLWindow>());
#endif

	return nullptr;
}

std::unique_ptr<pav::EventManager> pav::ManagerFactory::CreateEventManager()
{
#ifdef ENGINE_TYPE_GL_SDL
	return std::make_unique<SDLEventManager>();
#endif

	return nullptr;
}

std::unique_ptr<pav::RenderManager> pav::ManagerFactory::CreateRenderManager()
{
#ifdef ENGINE_TYPE_GL_SDL
	return std::make_unique<GLSDLRenderManager>();
#endif

	return nullptr;
}
