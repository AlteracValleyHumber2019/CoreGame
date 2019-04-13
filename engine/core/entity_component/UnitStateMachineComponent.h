#ifndef UITSTATEMACHINECOMPONENT_H
#define UITSTATEMACHINECOMPONENT_H
#include "UnitStateWrapper.h"
#include "UnitGameObject.h"

namespace pav 
{
	class UnitStateMachineComponent
	{
		/**
		* author	Ethan
		* date	4/2/2019
		* uses facade unitgamebject class, not fully implemented as this does not contain the real class
		*/
	public:
		UnitStateMachineComponent();
		~UnitStateMachineComponent();
		void Update(float deltatime);
	private:
		UnitGameObject* UnitGameObjectPtr;
		UnitStateWrapper State;
	};
}
#endif
