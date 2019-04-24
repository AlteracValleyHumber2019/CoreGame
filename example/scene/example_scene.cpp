#include "pav_pch.h"
#include "example_scene.h"
#include "core/entity_component/component/transform_component.h"

void ExampleScene::BeginScene()
{
	auto game_object = GetSECManager()->AddGameObject<pav::IGameObjectBase>("Example_GameObject");
	game_object->AddComponent<pav::TransformComponent>();
	gameState = new pav::GameState();
}

void ExampleScene::EndScene()
{
}

void ExampleScene::Update(const float delta_time)
{
	IScene::Update(delta_time);

	cout << "Updating";

	// Really non-efficient way to update the positions from the database:
	// To make this more dynamic, loop through all the objects that need updating rather than calling each on manually
	// Since I had to revert to an older commit, the scene doesn't properly contain that information
	gameState->UpdateGameState(0, "");
	gameState->UpdateGameState(1, "");
}

//! [ExampleScene setup event]
void ExampleScene::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
	IScene::SetupEngineEvents(event_attorney);

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