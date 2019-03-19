#include "pav_pch.h"
#include "i_ui.h"

pav::SECManager* pav::IUI::GetSECManager() {}

pav::IUI::IUI() : sec_manager_(std::make_unique<SECManager>()) {}

void pav::IUI::OnCreate(){}

void pav::IUI::OnDestroy(){}

void pav::IUI::Update(const float delta_time) {
	sec_manager_->Update(delta_time);
}