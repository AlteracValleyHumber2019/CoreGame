#include "pav_pch.h"
#include "CharacterComponent.h"

pav::CharacterComponent::CharacterComponent(IGameObjectBase* Owner, float Health_, float Damage_, glm::vec3 Position_) : IComponent<CharacterComponent, 1>::IComponent(Owner), Health(Health_), Damage(Damage_), Position(Position_) {}

void pav::CharacterComponent::MoveForward()
{
	Position.z += 10.0f;
}

void pav::CharacterComponent::MoveBackward()
{
	Position.z -= 10.0f;
}

void pav::CharacterComponent::MoveLeft()
{
	Position.x += 10.0f;
}

void pav::CharacterComponent::MoveRight()
{
	Position.x -= 10.0f;
}

void pav::CharacterComponent::Jump()
{
	Position.y += 10.0f;
}

void pav::CharacterComponent::Attack()
{
	
}