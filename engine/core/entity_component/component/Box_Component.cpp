#include "pav_pch.h"
#include "Box_Component.h"

pav::BoxComponent::BoxComponent(IGameObjectBase* Owner, const glm::vec3 minCoords, const glm::vec3 maxCoords) : IComponent<BoxComponent, 1>::IComponent(Owner) {

	BoxCollider.AABB::minCoords = minCoords;
	BoxCollider.AABB::maxCoords = maxCoords;

}
pav::BoxComponent::BoxComponent(IGameObjectBase* Owner, const AABB AABB) : IComponent<BoxComponent, 1>::IComponent(Owner) {
	BoxCollider.AABB::minCoords = AABB.minCoords;
	BoxCollider.AABB::maxCoords = AABB.maxCoords;
}

bool pav::BoxComponent::isPointInsideAABBB(const glm::vec3 point_, const AABB &box_) {
	if (point_.x >= box_.minCoords.x && point_.x <= box_.maxCoords.x)
		return true;
	else if (point_.y >= box_.minCoords.y && point_.y <= box_.maxCoords.y)
		return true;
	else if (point_.z >= box_.minCoords.z && point_.z <= box_.maxCoords.z)
		return true;
	else
		return false;
}

bool pav::BoxComponent::isAABBintersecting(const AABB &box1, const AABB &box2) {

	bool xOverlap = box1.minCoords.x <= box2.maxCoords.x && box1.maxCoords.x >= box2.minCoords.x;
	bool yOverlap = box1.minCoords.y <= box2.maxCoords.y && box1.maxCoords.y >= box2.minCoords.y;
	bool zOverlap = box1.minCoords.z <= box2.maxCoords.z && box1.maxCoords.z >= box2.minCoords.z;

	return xOverlap && yOverlap && zOverlap;		
}


bool pav::BoxComponent::isCapsuleIntersecting(const AABB &box_, const CapsuleComponent::CAPSULE &c_) {
	return true;
}