#include "pav_pch.h"
#include "example_scene.h"

void ExampleScene::BeginScene()
{
}

void ExampleScene::EndScene()
{
}

void ExampleScene::Update(const float delta_time)
{
	IScene::Update(delta_time);
}

//! [ExampleScene setup event]
void ExampleScene::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
	// Your event handle function bindings
	event_attorney->on_key_down->Connect(this, &ExampleScene::OnKeydown);
	// ...
	// ...
	// ...
}

void ExampleScene::OnKeydown(pav::KeyCode keycode)
{
	// Handle keydown event...
}
//! [ExampleScene setup event]