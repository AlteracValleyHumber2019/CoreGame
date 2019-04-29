#include "pav_pch.h"
#include "IUnitAction.h"

pav::IUnitAction::IUnitAction(UnitGameObject* UnitGameObjectPtr)
{
	/**
* author	Ethan
* date	4/16/2019
* get gameobject so we dont manipulate the real gameobject, and we only need certain aspects
* examples,name, race
*note to self - landon is creating the "Unit" gameobject class with the required types i believe
*/
	GameObjectPtr = UnitGameObjectPtr;
}


pav::IUnitAction::~IUnitAction()
{
}

void pav::IUnitAction::Execute()
{
	/**
* author	Ethan
* date	4/15/2019
* should become a factory taking in parameters to create a action based on conditions such as state, unit type, hit condition, button pressed etc 
*/
}