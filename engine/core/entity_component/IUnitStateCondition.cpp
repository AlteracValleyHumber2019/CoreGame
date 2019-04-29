#include "pav_pch.h"
#include "IUnitStateCondition.h"


bool pav::IUnitStateCondition::Condition(IUnitState stateCheck)
{
	/**
* author	Ethan
* date	4/15/2019
* swap betwee conditions based on checks
* each unique gameobject can have the truestate and failstate manipulated else where depending on changes to condition need
* state name helps deprive what we look for, and what we change based on conditions
*/
	if (stateCheck.Statename == check) 
	{
		stateCheck.Statename = TrueState.Statename;
		//using state name only currently as we should also enherit Actions from true or false states. ote - ask jaymie later
		return true;
	}
	else 
	{ 
		stateCheck.Statename = FailState.Statename;
		//stateCheck->actions[1] = FailState->actions[3];???
		//stateCheck->actions.insert(FailState->actions[3]);???
		return false; 
	}
}