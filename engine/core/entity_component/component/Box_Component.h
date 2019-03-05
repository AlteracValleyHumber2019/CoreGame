#ifndef BOX_COMPONENT_H
#define BOX_COMPONENT_H

#include "../i_Component.h"
#include "../i_game_object.h"
#include "Capsule_Component.h"

namespace pav{
	
class BoxComponent final : public IComponent<BoxComponent, 1>
{		
public:
	
	struct AABB
	{
		glm::vec3 minCoords;
		glm::vec3 maxCoords;
	};
	AABB BoxCollider;

	BoxComponent(IGameObjectBase* Owner, const glm::vec3 minCoords, const glm::vec3 maxCoords);
	BoxComponent(IGameObjectBase* Owner, const AABB AABB);

	void setMinCoords(const glm::vec3 minCoords_);
	void setMaxCoords(const glm::vec3 maxCoords_);
	/*Check for point inside AABB colliding*/
	bool isPointInsideAABBB(const glm::vec3 point_,const AABB &box_);
	/*Check for two AABB's colliding*/
	bool isAABBintersecting(const AABB &box1, const AABB &box2);
	/*TODO*/
	bool isCapsuleIntersecting(const AABB &box_, const CapsuleComponent::CAPSULE &c_);
	
	glm::vec3 getCenter() const;

};

inline glm::vec3 BoxComponent::getCenter() const {

	glm::vec3 centerPoint; 

	centerPoint.x = BoxCollider.minCoords.x + BoxCollider.maxCoords.x * 0.5;
	centerPoint.y = BoxCollider.minCoords.y + BoxCollider.maxCoords.y * 0.5;
	centerPoint.z = BoxCollider.minCoords.z + BoxCollider.maxCoords.z * 0.5;

	return centerPoint;
}

inline void BoxComponent::setMinCoords(const glm::vec3 minCoords_)  {
	BoxCollider.minCoords = minCoords_;
}
inline void BoxComponent::setMaxCoords(const glm::vec3 maxCoords_) {
	BoxCollider.maxCoords = maxCoords_;
}

}
#endif