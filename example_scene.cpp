#include "pav_pch.h"
#include "example_scene.h"

void pav_game::ExampleScene::BeginScene()
{
}

void pav_game::ExampleScene::EndScene()
{
}

void pav_game::ExampleScene::Update(const float delta_time)
{
}

void pav_game::ExampleScene::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
	event_attorney->on_key_down->Connect(this, &ExampleScene::OnKeydown);
}

void pav_game::ExampleScene::OnKeydown(pav::KeyCode kc)
{
	printf("Keydown\n");
}
