#ifndef UNITSTATEWRAPPER_H
#define UNITSTATEWRAPPER_H

#include "IUnitState.h"
#include "IUnitStateCondition.h"

namespace pav
{
class UnitStateWrapper : public IUnitState/*, public IUnitStateCondition, public IUnitAction*/
{
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