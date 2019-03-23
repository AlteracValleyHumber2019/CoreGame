#include "pav_pch.h"
#include "RigidBodyComponent.h"


void RigidBodyComponent::Update(float DeltaTime) 
{
	Position_.x += (Velocity_.x * DeltaTime) + (0.5f * Acceleration_.x * (DeltaTime * DeltaTime));
	Position_.y += (Velocity_.y * DeltaTime) + (0.5f * (Acceleration_.y + GravityScale_)* (DeltaTime * DeltaTime));
	Position_.z += (Velocity_.z * DeltaTime) + (0.5f * Acceleration_.z * (DeltaTime * DeltaTime));

	Velocity_.x += Acceleration_.x * DeltaTime;
	Velocity_.y += (Acceleration_.y + GravityScale_)* DeltaTime;
	Velocity_.z += Acceleration_.z * DeltaTime;
}


void RigidBodyComponent::ApplyForce(glm::vec3& force) 
{
	Acceleration_.x = force.x / Mass_;
	Acceleration_.y = force.y / Mass_;
	Acceleration_.z = force.z / Mass_;
}

void RigidBodyComponent::SetMass(float mass) 
{
	Mass_ = mass;
}

void RigidBodyComponent::SetPos(glm::vec3 Position) 
{
	Position_ = Position;
}

void RigidBodyComponent::SetGravity(float gravity) 
{
	GravityScale_ = gravity;
}

glm::vec3 RigidBodyComponent::GetPos() 
{
	return Position_;
}