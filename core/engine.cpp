#include "pav_pch.h"
#include "engine.h"
#include "manager_factory.h"

pav::Engine::Engine() :
	running_(true),
	window_info_(800, 600, 0, 0, "Project Alterac Valley"),
	scene_manager(ManagerFactory::CreateSceneManager()),
	window_manager(ManagerFactory::CreateWindowManagerManager()),
	event_manager(ManagerFactory::CreateEventManager()),
	render_manager(ManagerFactory::CreateRenderManager())
{
}

void pav::Engine::StartEngine()
{
	render_manager->Initialize();
	window_manager->Initialize();
	scene_manager->Initialize();
	event_manager->Initialize();

	window_manager->CreateWindow
	(
		window_info_.Prototype()
	);

	while (running_)
	{
		Update(1.f); // TODO: replace with actual delta time
	}

	EndEngine();
}

void pav::Engine::EndEngine()
{
	event_manager->End();
	scene_manager->End();
	window_manager->End();
	render_manager->End();
}

void pav::Engine::Update(const float delta_time)
{
	event_manager->Update(delta_time);
	window_manager->Update(delta_time);
	scene_manager->Update(delta_time);
	render_manager->Update(delta_time);
}

void pav::Engine::SetWindowInfo(WindowInfo&& window_info)
{
	window_info_ = std::move(window_info);
}
