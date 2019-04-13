#include "pav_pch.h"
#include "Box_Component.h"

pav::BoxComponent::BoxComponent(IGameObjectBase* Owner, const glm::vec3 minCoords, const glm::vec3 maxCoords) : IComponent<BoxComponent, 1>::IComponent(Owner) {

	mBoxCollider.AABB::min = minCoords;
	mBoxCollider.AABB::max = maxCoords;

}
pav::BoxComponent::BoxComponent(IGameObjectBase* Owner, const AABB AABB) : IComponent<BoxComponent, 1>::IComponent(Owner) {
	mBoxCollider.AABB::min = AABB.min; 
	mBoxCollider.AABB::max = AABB.min;
}

pav::BoxComponent::~BoxComponent()
{
}
