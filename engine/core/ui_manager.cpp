#include "pav_pch.h"
#include "ui_manager.h"

void pav::UIManager::Initialize()
{
}

void pav::UIManager::End()
{
}

void pav::UIManager::Update(const float delta_time)
{
	if (current_ui_ != nullptr)
	{
		current_ui_->Update(delta_time);
	}
}

pav::IUI* pav::UIManager::AddUI(std::string&& Name, std::unique_ptr<IUI>&& scene)
{
	// Check if manager do not have this scene
	if (uis_.find(Name) == uis_.end())
	{
		uis_.insert(std::make_pair(std::move(Name), std::move(scene)));
	}

	return nullptr;
}

pav::IUI* pav::UIManager::GetUI(std::string&& Name)
{
	// Check if manager have scene
	if (uis_.find(Name) != uis_.end())
	{
		return uis_.at(Name).get();
	}

	return nullptr;
}

void pav::UIManager::RemoveUI(std::string&& Name)
{
	// Check if manager have scene
	if (uis_.find(Name) != uis_.end())
	{
		uis_.erase(Name);
	}
}

void pav::UIManager::SwitchUI(std::string && Name)
{
	if (current_ui_ != nullptr)
	{
		current_ui_->EndScene(); // Scene end logic
	}

	current_ui_ = uis_.at(Name).get();
	current_ui_->SetupEngineEvents(event_attorney_); // Forward event
	current_ui_->BeginScene(); // Scene begin logic
}

void pav::UIManager::SetupEngineEvents(EventAttorney* event_attorney)
{
	event_attorney_ = event_attorney;
}
