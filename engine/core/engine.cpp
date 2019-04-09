#include "pav_pch.h"
#include "engine.h"
#include "manager_factory.h"

pav::Engine::Engine() :
	running_(true),
	window_info_(800, 600, 0, 0, "Project Alterac Valley"),
	scene_manager(ManagerFactory::CreateSceneManager()),
	ui_manager(ManagerFactory::CreateUIManager()),
	window_manager(ManagerFactory::CreateWindowManagerManager()),
	event_manager(ManagerFactory::CreateEventManager()),
	render_manager(ManagerFactory::CreateRenderManager())
{
#ifndef ENGINE_TYPE_GL_SDL
	PAV_ASSERT(false, PRECOMPILED_ENGINE_SETTING_UNDEFINED);
#endif // !ENGINE_TYPE_GL_SDL
}

void pav::Engine::InitEngine()
{
	render_manager->Initialize();
	window_manager->Initialize();
	scene_manager->Initialize();
	ui_manager->Initialize();
	event_manager->Initialize();

	// Inject events
	event_attorney_ = std::make_unique<EventAttorney>();
	event_attorney_->on_input = &event_manager->on_input;
	event_attorney_->on_key_down = &event_manager->on_key_down;
	event_attorney_->on_key_hold = &event_manager->on_key_hold;
	event_attorney_->on_key_up = &event_manager->on_key_up;
	event_attorney_->on_mouse_button_down = &event_manager->on_mouse_button_down;
	event_attorney_->on_mouse_button_up = &event_manager->on_mouse_button_up;

	scene_manager->SetupEngineEvents(event_attorney_.get());
	ui_manager->SetupEngineEvents(event_attorney_.get());

	window_manager->CreateWindow
	(
		window_info_.Prototype()
	);
}

void pav::Engine::StartEngine()
{
	// Game loop
	while (running_)
	{
		Update(1.f); // #TODO: replace with actual delta time
	}

	EndEngine();
}

void pav::Engine::EndEngine()
{
	event_manager->End();
	scene_manager->End();
	ui_manager->End();
	window_manager->End();
	render_manager->End();
}

void pav::Engine::Update(const float delta_time)
{
	event_manager->Update(delta_time);
	window_manager->Update(delta_time);
	scene_manager->Update(delta_time);
	ui_manager->Update(delta_time);
	render_manager->Update(delta_time);
}

void pav::Engine::SetWindowInfo(WindowInfo&& window_info)
{
	window_info_ = std::move(window_info);
}
