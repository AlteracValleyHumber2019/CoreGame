#include "pav_pch.h"
#include "camera_component.h"

void pav::CameraComponent::Update(const float delta_time)
{
}

float pav::CameraComponent::GetYaw() const
{
	return yaw_;
}

float pav::CameraComponent::GetPitch() const
{
	return pitch_;
}

void pav::CameraComponent::SetYaw(const float value)
{
	yaw_ = value;
}

void pav::CameraComponent::SetPitch(const float value)
{
	pitch_ = value;
}
