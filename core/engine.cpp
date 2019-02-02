#include "pav_pch.h"
#include "engine.h"

pav::Engine::Engine() :
running_(true),
scene_manager(std::make_unique<SceneManager>())
{
}

void pav::Engine::StartEngine()
{
	scene_manager->Initialize();

	while (running_)
	{
		Update(1.f); // TODO: replace with actual delta time
	}

	EndEngine();
}

void pav::Engine::EndEngine()
{
	scene_manager->End();
}

void pav::Engine::Update(const float delta_time)
{
	scene_manager->Update(delta_time);
}
