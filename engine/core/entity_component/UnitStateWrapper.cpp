#include "pav_pch.h"
#include "UnitStateWrapper.h"


pav::UnitStateWrapper::UnitStateWrapper()
{
}


pav::UnitStateWrapper::~UnitStateWrapper()
{
}

void pav::UnitStateWrapper::Update() 
{
	/**
* author	Ethan
* date	4/15/2019
* got a better understanding of how conditions should work. This should be how we check condition is met, and change state
*/
	if (Condition->Condition(CurrentState*))
	{
		CurrentState->Update();
	}
}