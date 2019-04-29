#include "pav_pch.h"
#include "IUnitState.h"


pav::IUnitState::IUnitState(UnitGameObject* UnitGameObjectPtr)
{
	/**
* author	Ethan
* date	4/15/2019
* we should be defaulting state upon construction
* added statename to help understand wat state we are currently in damaged, attacking, running etc
*/
	if (UnitGameObjectPtr->UnitType == "Knight") 
	{
		Statename = "Default";
	}
	else if (UnitGameObjectPtr->UnitType == "Assassin") 
	{
		Statename = "Default";
	}
	else if (UnitGameObjectPtr->UnitType == "Priest") 
	{
		Statename = "Default";
	}
	else if (UnitGameObjectPtr->UnitType == "Priest")
	{
		Statename = "Default";
	}
	else
	{
		//note to self add error message for when type is beyond the constructors check
	}

}


pav::IUnitState::~IUnitState()
{
}

void pav::IUnitState::Update()
{
	/**
* author	Ethan
* date	4/15/2019
* what do i do with actions? more research required. I'll ask Jaymie
*/
	Actions[0]->Execute();
	/**
* author	Ethan
* date	4/22/2019
* ammendent group said to drop statemachine, i'll try working on MVP or help landon maybe???
*/
}