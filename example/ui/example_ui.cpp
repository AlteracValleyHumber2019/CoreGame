#include "pav_pch.h"
#include "example/ui/example_ui.h"
#include "core/entity_component/component/transform_component.h"

void ExampleUI::BeginScene()
{
	auto game_object = GetSECManager()->AddGameObject<pav::IGameObjectBase>("Example_UIObject");
	game_object->AddComponent<pav::TransformComponent>();
}

void ExampleUI::EndScene()
{
}

void ExampleUI::Update(const float delta_time)
{
	IUI::Update(delta_time);
}