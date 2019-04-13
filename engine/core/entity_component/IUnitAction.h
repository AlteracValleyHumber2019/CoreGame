#ifndef IUNITACTION_H
#define IUNITACTION_H

#include "i_game_object.h"//?
#include "UnitGameObject.h"
namespace pav 
{
	class IUnitAction
	{
		/**
	* author	Ethan
	* date	4/2/2019
	* uses facade unitgamebject class, not fully implemented as this does not contain the real class
	*/
	public:
		IUnitAction(UnitGameObject* UnitGameObjectPtr);
		~IUnitAction();
		virtual void Execute() =0;
	};
}
#endif
