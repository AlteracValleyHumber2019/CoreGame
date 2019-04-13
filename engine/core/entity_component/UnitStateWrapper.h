#ifndef UNITSTATEWRAPPER_H
#define UNITSTATEWRAPPER_H

#include "IUnitState.h"
#include "IUnitStateCondition.h"

namespace pav
{
class UnitStateWrapper : public IUnitState/*, public IUnitStateCondition, public IUnitAction*/
{
	/**
	* author	Ethan
	* date	4/2/2019
	* i understand what this is intended to do... but how it works and interacts with the interfaces i do not
	*/
public:
	UnitStateWrapper();
	~UnitStateWrapper();
	void Update();
private:
	std::unique_ptr<IUnitState> CurrentState;
	std::unique_ptr<IUnitStateCondition> Condition;
};
}
#endif