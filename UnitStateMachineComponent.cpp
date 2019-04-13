#include "pav_pch.h"
#include "UnitStateMachineComponent.h"


pav::UnitStateMachineComponent::UnitStateMachineComponent()
{
}


pav::UnitStateMachineComponent::~UnitStateMachineComponent()
{
}

void pav::UnitStateMachineComponent::Update(float deltatime)
{
	State.Update();
}