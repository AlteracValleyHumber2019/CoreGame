#ifndef CAPSULE_COMPONENT_H
#define CAPSULE_COMPONENT_H

#include "../i_Component.h"
#include "../i_game_object.h"

namespace pav {

	class CapsuleComponent final :  public IComponent<CapsuleComponent, 0>
	{

	public:

		struct CAPSULE
		{
			glm::vec3 position;
			float radius;
			float height;
		};

		CAPSULE capsuleCollider;

		CapsuleComponent(IGameObjectBase* Owner, float radius_, float height_);
		CapsuleComponent(IGameObjectBase* Owner, CAPSULE capsuleCollider_);

		bool isPointInsideCapsule(glm::vec3 point_, CAPSULE &capsuleCollider_);
		bool isCapsuleIntersecting(const CAPSULE &capsuleCollider_1, const CAPSULE &capsuleCollider_2);
	
	};
}
#endif