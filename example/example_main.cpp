//! [ExampleMain entry point]

#include "pav_pch.h"
#include "engine/core/engine.h"
#include "scene/example_scene.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<pav::Engine> engine = std::make_unique<pav::Engine>();

	engine->SetWindowInfo({ 800, 600, 100, 100, "Project Alterac Valley" });
	engine->InitEngine();

	engine->scene_manager->AddScene("example_scene", std::make_unique<ExampleScene>());
	engine->scene_manager->SwitchScene("example_scene");

	engine->StartEngine();

	return 0;
}

//! [ExampleMain entry point]