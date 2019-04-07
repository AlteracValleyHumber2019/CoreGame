#include "pav_pch.h"
#include "window_manager.h"

pav::WindowManager::WindowManager(std::unique_ptr<IWindow>&& window) :
	window_(std::move(window))
{
}

void pav::WindowManager::Initialize()
{
}

void pav::WindowManager::End()
{
}

void pav::WindowManager::Update(const float delta_time)
{
	window_->Update(delta_time);
}

void pav::WindowManager::MakeWindow(WindowInfo&& window_info)
{
	window_->MakeWindow(std::move(window_info));
	window_->SetAsContext();
}

pav::IWindow* pav::WindowManager::GetCurrentWindow()
{
	return window_.get();
}
