#include "pav_pch.h"
#include "invoke_skill_command.h"


void pav::InvokeSkillCommand::Execute(DataManager *manager_)
{

}

void pav::InvokeSkillCommand::Accept(IServerCommandVisitor &visitor_)
{
	visitor_.Visit(this);
}