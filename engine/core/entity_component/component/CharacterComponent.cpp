#include "pav_pch.h"
#include "CharacterComponent.h"

pav::CharacterComponent::CharacterComponent(IGameObjectBase* Owner, float Health_, float Damage_, glm::vec3 Position_) : IComponent<CharacterComponent, 1>::IComponent(Owner), Health(Health_), Damage(Damage_), Position(Position_) {}

void pav::CharacterComponent::MoveForward()
{
	position_mat4_ = glm::translate(glm::mat4(1.f), Position.z + glm::vec3(0.0f, 0.0f, 10.0f));
}

void pav::CharacterComponent::MoveBackward()
{

	position_mat4_ = glm::translate(glm::mat4(1.f), Position.z - glm::vec3(0.0f, 0.0f, 10.0f));
}

void pav::CharacterComponent::MoveLeft()
{
	position_mat4_ = glm::translate(glm::mat4(1.f), Position.x - glm::vec3(10.0f, 0.0f, 0.0f));
}

void pav::CharacterComponent::MoveRight()
{
	position_mat4_ = glm::translate(glm::mat4(1.f), Position.x + glm::vec3(10.0f, 0.0f, 0.0f));
}


void pav::CharacterComponent::Attack()
{
	//spawn 5 units infront of Z of player and add force on projectile
	Position.z = Position.z + 10.0f;
	ApplyForce(glm::vec3(0.0f,0.0f,50.0f));
}

void pav::CharacterComponent::ApplyForce(const glm::vec3 force_)
{
	float mass = 100.0f;
	glm::vec3 acceleration;

	acceleration.x = force_.x / mass;
	acceleration.y = force_.y / mass;
	acceleration.z = force_.z / mass;


}