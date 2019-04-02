#include "pav_pch.h"
#include "i_ui.h"

pav::SECManager* pav::IUI::GetSECManager()
{
	return sec_manager_.get();
}

pav::IUI::IUI() : sec_manager_(std::make_unique<SECManager>()) {}

void pav::IUI::BeginScene(){}

void pav::IUI::EndScene(){}

void pav::IUI::Update(const float delta_time)
{
	sec_manager_->Update(delta_time);
}

void pav::IUI::SetupEngineEvents(EventAttorney* event_attorney)
{
	sec_manager_->SetupEngineEvents(event_attorney);
}