#include "pav_pch.h"
#include "example/ui/example_ui.h"
#include "core/entity_component/component/transform_component.h"
#include "core/entity_component/component/sdl_image_component.h"

void ExampleUI::BeginScene()
{
	auto game_object = GetSECManager()->AddGameObject<pav::IGameObjectBase>("Example_UIObject");
	game_object->AddComponent<pav::TransformComponent>();
	game_object->AddComponent<pav::SDLImageComponent>();

	/* This is purely for testing purposes since the Component Manager and Render calss weren't in my version
		Delete in final build
	pav::TransformComponent *t;
	t = new pav::TransformComponent(game_object);
	t->SetPosition(glm::vec3(0, 0, 0));

	pav::TransformComponent *t2;
	t2 = new pav::TransformComponent(game_object);
	t2->SetPosition(glm::vec3(100, 100, 0));

	pav::SDLImageComponent* i;
	i = new pav::SDLImageComponent(game_object);
	i->SetImage("jetski.bmp");
	i->Begin();
	i->Render(t);

	pav::SDLImageComponent* i2;
	i2 = new pav::SDLImageComponent(game_object);
	i2->SetImage("healthbar.bmp");
	i2->Begin();
	i2->Render(t2);*/
}

void ExampleUI::EndScene()
{
}

void ExampleUI::Update(const float delta_time)
{
	IUI::Update(delta_time);
}

void ExampleUI::Render()
{
}

//! [ExampleScene setup event]
void ExampleUI::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
	IUI::SetupEngineEvents(event_attorney);
}