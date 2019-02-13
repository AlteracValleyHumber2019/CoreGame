#include "pav_pch.h"
#include "sec_manager.h"

#include "game_object_manager.h"
#include "component_manager.h"

pav::SECManager::SECManager() :
	game_object_manager_(std::make_unique<GameObjectManager>()),
	component_manager_(std::make_unique<ComponentManager>())
{
}

void pav::SECManager::RemoveGameObject(std::string&& name)
{
	game_object_manager_->RemoveGameObject(std::move(name));
}

void pav::SECManager::Update(float delta_time)
{
	game_object_manager_->Update(delta_time);
}

void pav::SECManager::SetupEngineEvents(EventAttorney* event_attorney)
{
	event_attorny_ = event_attorney;

	game_object_manager_->SetupEngineEvents(event_attorny_);
	component_manager_->SetupEngineEvents(event_attorny_);
}
