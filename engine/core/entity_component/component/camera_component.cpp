#include "pav_pch.h"
#include "camera_component.h"

void pav::CameraComponent::UpdateCamera()
{
	// Calculate the new Front vector
	glm::vec3 front;
	front.x = cos(glm::radians(pitch_)) * cos(glm::radians(yaw_));
	front.y = sin(glm::radians(pitch_));
	front.z = cos(glm::radians(pitch_)) * sin(glm::radians(yaw_));
	camera_front_ = glm::normalize(front);

	// Also re-calculate the Right and Up vector
	camera_right_ = glm::normalize(glm::cross(camera_front_, glm::vec3(0.0f, 1.0f, 0.0f)));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	camera_up_ = glm::normalize(glm::cross(camera_right_, camera_front_));
}

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

glm::vec3 pav::CameraComponent::GetRight() const
{
	return camera_right_;
}

glm::vec3 pav::CameraComponent::GetUp() const
{
	return camera_up_;
}

glm::vec3 pav::CameraComponent::GetFront() const
{
	return camera_front_;
}

void pav::CameraComponent::SetYaw(const float value)
{
	yaw_ = value;
}

void pav::CameraComponent::SetPitch(const float value)
{
	pitch_ = value;
}
