#ifndef CHARACTER_COMPONENT_H
#define CHARACTER_COMPONENT_H

#include "../i_Component.h"
#include "../i_game_object.h"

namespace pav{

class CharacterComponent final : public IComponent<CharacterComponent, 1>
{
private:
	float Health;
	float Damage;
	glm::vec3 Position;
public:

	CharacterComponent(IGameObjectBase* Owner, float Health_,float Damage_, glm::vec3 Position_);

	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
	
	void Jump();

	void Attack();

};

}

#endif