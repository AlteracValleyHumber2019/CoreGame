#ifndef IUNITSTATECONDITION_H
#define IUNITSTATECONDITION_H

#include "IUnitState.h"
#include <string>;
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
	bool Condition(IUnitState stateCheck);
	std::string check;
	private:
		IUnitState TrueState;
		IUnitState FailState;
	};
}
#endif
