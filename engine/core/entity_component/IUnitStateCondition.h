#ifndef IUNITSTATECONDITION_H
#define IUNITSTATECONDITION_H

#include "IUnitState.h"
namespace pav
{
	class IUnitStateCondition
	{
	public:
		/**
* author	Ethan
* date	4/2/2019
* swaps between truestate and falsestate based on conditions met
*/
	virtual	bool Condition() = 0;
	private:
		IUnitState TrueState;
		IUnitState FailState;
	};
}
#endif
