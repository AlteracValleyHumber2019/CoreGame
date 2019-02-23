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

}

void pav::TransformComponent::SetRotation(const glm::vec3& rot)
{

}

void pav::TransformComponent::SetScale(const glm::vec3& scale)
{

}

pav::TransformComponent::TransformComponent(IGameObjectBase* owner) :
	IComponent<TransformComponent, 0>::IComponent(owner)
{
}
