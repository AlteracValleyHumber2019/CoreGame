#include "pav_pch.h"
#include "scene_manager.h"

void pav::SceneManager::Initialize()
{
}

void pav::SceneManager::End()
{
}

void pav::SceneManager::Update(const float delta_time)
{
	if (current_scene_ != nullptr)
	{
		current_scene_->Update(delta_time);
	}
}

pav::IScene* pav::SceneManager::AddScene(std::string&& Name, std::unique_ptr<IScene>&& scene)
{
	// Check if manager do not have this scene
	if (scenes_.find(Name) == scenes_.end())
	{
		scenes_.insert(std::make_pair(std::move(Name), std::move(scene)));
	}

	return nullptr;
}

pav::IScene* pav::SceneManager::GetScene(std::string&& Name)
{
	// Check if manager have scene
	if (scenes_.find(Name) != scenes_.end())
	{
		return scenes_.at(Name).get();
	}

	return nullptr;
}

void pav::SceneManager::RemoveScene(std::string&& Name)
{
	// Check if manager have scene
	if (scenes_.find(Name) != scenes_.end())
	{
		scenes_.erase(Name);
	}
}

void pav::SceneManager::SwitchScene(std::string && Name)
{
	if (current_scene_ != nullptr)
	{
		current_scene_->EndScene(); // Scene end logic
	}

	current_scene_ = scenes_.at(Name).get();
	current_scene_->SetupEngineEvents(event_attorney_); // Forward event
	current_scene_->BeginScene(current_window_ptr_); // Scene begin logic
}

void pav::SceneManager::SetupEngineEvents(EventAttorney* event_attorney)
{
	event_attorney_ = event_attorney;
}

void pav::SceneManager::SetWindowPtr(WindowType* win)
{
	current_window_ptr_ = win;
}
