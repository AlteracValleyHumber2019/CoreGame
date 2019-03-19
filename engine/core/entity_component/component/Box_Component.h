#ifndef BOX_COMPONENT_H
#define BOX_COMPONENT_H

#include "../i_Component.h"
#include "../i_game_object.h"

namespace pav{

class BoxComponent final : public IComponent<BoxComponent, 1>
{
private:
	
	struct AABB
	{
		glm::vec3 min;
		glm::vec3 max;
	};
public:
	AABB mBoxCollider;
	BoxComponent(IGameObjectBase* Owner, const glm::vec3 minCoords, const glm::vec3 maxCoords);
	BoxComponent(IGameObjectBase* Owner, const AABB AABB);
	glm::vec3 getCenter() const;
	~BoxComponent();

};

inline glm::vec3 BoxComponent::getCenter() const {

	glm::vec3 centerPoint; 

	centerPoint.x = mBoxCollider.min.x + mBoxCollider.max.x * 0.5;
	centerPoint.y = mBoxCollider.min.y + mBoxCollider.max.y * 0.5;
	centerPoint.z = mBoxCollider.min.z + mBoxCollider.max.z * 0.5;

	return centerPoint;
}

}
#endif