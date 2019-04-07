#include "pav_pch.h"
#include "invoke_skill_command.h"


void pav::InvokeSkillCommand::Execute()
{

}

void pav::InvokeSkillCommand::Accept(IServerCommandVisitor &visitor_)
{
	visitor_.visit(*this);
}