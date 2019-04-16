#ifndef CHARACTER_H
#define CHARACTER_H

#include "i_component.h"
#include "i_game_object.h"
#include "component/unit_component.h"
#include "component/stat_component.h"
#include "component/transform_component.h"

namespace pav
{
	/**
	 * \class	character
	 *
	 * \brief	A character GameObject. Has a stat component,  transform component, collisions.
	 *
	 * \author	Landon
	 * \date	3/10/2019
 */
	class character : public IGameObjectBase
	{
	public:
		character();
		~character();

		StatComponent* CharacterStats;
		TransformComponent* Transform;
		UnitComponent* UnitCompPtr;
		// This still needs to be implemented
		// CapsuleCollider* Collider;

		inline unsigned int GetID() { return unitID; };
		void Update(const float deltaTime);

	private:
		unsigned int unitID;
	};
}


#endif CHARACTER_H
