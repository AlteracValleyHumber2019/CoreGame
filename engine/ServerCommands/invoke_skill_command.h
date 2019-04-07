#pragma once

#include "i_Server_Command.h"


namespace pav{

class InvokeSkillCommand : public IServerCommand
{
public:

	class ISkill *skill;

	void Execute(/*DataManager manager_*/);
	void Accept(IServerCommandVisitor &visitor_);

};
}

