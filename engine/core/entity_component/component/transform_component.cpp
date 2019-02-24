#include "pav_pch.h"
#include "transform_component.h"

glm::vec3 pav::TransformComponent::GetPosition() const
{
	return position_;
}

glm::vec3 pav::TransformComponent::GetRotation() const
{
	return rotation_;
}

glm::vec3 pav::TransformComponent::GetScale() const
{
	return scale_;
}

void pav::TransformComponent::SetPosition(const glm::vec3& pos)
{
	position_ = pos;
	position_mat4_ = glm::translate(glm::mat4(1.f), pos);
}

void pav::TransformComponent::SetRotation(const glm::vec3& euler)
{
	rotation_ = euler;
	rotation_mat4_ = glm::mat4_cast(glm::quat(euler));
}

void pav::TransformComponent::SetRotation(const glm::vec3 & axis, const float angle)
{
	rotation_ = axis * angle;
	rotation_mat4_ = glm::mat4_cast(glm::angleAxis(angle, axis));
}

void pav::TransformComponent::SetScale(const glm::vec3& scale)
{
	scale_ = scale;
	scale_mat4_ = glm::scale(glm::mat4(1.f), scale);
}

pav::TransformComponent::TransformComponent(IGameObjectBase* owner) :
	IComponent<TransformComponent, 0>::IComponent(owner)
{
}

void pav::TransformComponent::Begin()
{
}

void pav::TransformComponent::End()
{
}

void pav::TransformComponent::Update(const float delta_time)
{
}

void pav::TransformComponent::SetupEngineEvents(EventAttorney* event_attorney)
{
}
