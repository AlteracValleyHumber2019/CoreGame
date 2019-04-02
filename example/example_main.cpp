//! [ExampleMain entry point]

#include "pav_pch.h"
#include "engine/core/engine.h"
#include "scene/debug_scene.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<pav::Engine> engine = std::make_unique<pav::Engine>();

	engine->SetWindowInfo({ 800, 600, 100, 100, "Project Alterac Valley" });

	//Implementation of the camera for the scene[BP]        //Camera's Starting Position   //Camera's Target Position   //Camera's "Up" Vector    //Camera's Default Speed
	engine->camera = std::unique_ptr<SDLCamera>(new SDLCamera(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 1.0f));

	engine->InitEngine();

	engine->scene_manager->AddScene("debug_scene", std::make_unique<DebugScene>());
	engine->scene_manager->SwitchScene("debug_scene");

	engine->StartEngine();

	return 0;
}

//! [ExampleMain entry point]
