#ifndef UNIT_COMPONENT_H
#define UNIT_COMPONENT_H

#include "../i_component.h"
#include "../i_game_object.h"


namespace pav {

	class UnitComponent : public IComponent<UnitComponent, 0>
	{
	public:
		UnitComponent(IGameObjectBase* owner);

		void MoveTowards(glm::vec3 position);
		void Jump();
		void ApplyDamage(float amount);
		void Die();

	private:

	};

}

#endif //UNIT_COMPONENT_H