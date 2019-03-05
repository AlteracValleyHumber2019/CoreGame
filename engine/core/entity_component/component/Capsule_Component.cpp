#include "pav_pch.h"
#include "Capsule_Component.h"


pav::CapsuleComponent::CapsuleComponent(IGameObjectBase* Owner, float radius_, float height_) : IComponent<CapsuleComponent, 0>::IComponent(Owner) {
	capsuleCollider.radius = radius_;
	capsuleCollider.height = height_;
}


pav::CapsuleComponent::CapsuleComponent(IGameObjectBase* Owner, CAPSULE capsuleCollider_) : IComponent<CapsuleComponent, 0>::IComponent(Owner) {
	capsuleCollider.radius = capsuleCollider_.radius;
	capsuleCollider.height = capsuleCollider_.height;
}

bool pav::CapsuleComponent::isPointInsideCapsule(glm::vec3 point_, CAPSULE &capsuleCollider_) {

	bool hasCollided = false;
	
	/*glm::legnth() - OPENGL CALCULATE MAGNITUDE*/
	float distance = glm::length(point_.x - capsuleCollider_.position.x);

	if ((glm::length(point_.x - capsuleCollider_.position.x) <= capsuleCollider_.radius) && (capsuleCollider_.position.y <= capsuleCollider_.height)) {
		hasCollided = true;
	}
	else if((glm::length(point_.y - capsuleCollider_.position.y) <= capsuleCollider_.radius) && (capsuleCollider_.position.y <= capsuleCollider_.height)) {
		hasCollided = true;
	}
	else if ((glm::length(point_.z - capsuleCollider_.position.z) <= capsuleCollider_.radius) && (capsuleCollider_.position.y <= capsuleCollider_.height)) {
		hasCollided = true;
	}
	else {
		hasCollided = false;
	}

	return hasCollided;
}

bool pav::CapsuleComponent::isCapsuleIntersecting(const CAPSULE &capsuleCollider_1, const CAPSULE &capsuleCollider_2) {
	
	bool hasCollided = false;

	float distance = glm::length(capsuleCollider_1.position - capsuleCollider_2.position);

	if (distance <= (capsuleCollider_1.radius + capsuleCollider_2.radius)) {
		hasCollided = true;
	}
	else {
		hasCollided = false;
	}
	
	return hasCollided;
}