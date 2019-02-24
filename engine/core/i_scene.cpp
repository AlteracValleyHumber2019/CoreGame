#include "pav_pch.h"
#include "i_scene.h"

pav::SECManager* pav::IScene::GetSECManager()
{
	return sec_manager_.get();
}

pav::IScene::IScene() :
	sec_manager_(std::make_unique<SECManager>())
{
}

void pav::IScene::BeginScene()
{
}

void pav::IScene::EndScene()
{
}

void pav::IScene::Update(const float delta_time)
{
	sec_manager_->Update(delta_time);
}

void pav::IScene::SetupEngineEvents(EventAttorney* event_attorney)
{
	sec_manager_->SetupEngineEvents(event_attorney);
}
