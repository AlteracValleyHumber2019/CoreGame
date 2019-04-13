#ifndef IUNITSTATE_H
#define IUNITSTATE_H

#include "IUnitAction.h"
#include "UnitGameObject.h"
namespace pav {
	class IUnitState
		/**
		* author	Ethan
		* date	4/2/2019
		* uses facade unitgamebject class, not fully implemented as this does not contain the real class
		*/
	{
	public:
		IUnitState(UnitGameObject* UnitGameObjectPtr);
		~IUnitState();
		void Update();
	private:
		std::vector<std::unique_ptr<IUnitAction>> Actions;
	};
}
#endif