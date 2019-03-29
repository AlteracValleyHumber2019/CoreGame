#pragma once

#include "ISkill.h"
namespace pav{
class InvokeSkillCommand : public ISkill<float>
{
public:

	ISkill *skill;

	void Execute(/*DataManager manager_*/);

};
}

