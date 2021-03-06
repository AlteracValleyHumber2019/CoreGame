﻿#include "pav_pch.h"
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
}

void pav::WindowManager::CreateWindow(WindowInfo&& window_info)
{
	window_->CreateWindow(std::move(window_info));
	window_->SetAsContext();
}
