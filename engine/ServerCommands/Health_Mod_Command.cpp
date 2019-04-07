#include "pav_pch.h"
#include "Health_Mod_Command.h"


void pav::HealthModCommand::Execute(/*DataManager manager_*/)
{

}

void pav::HealthModCommand::Accept(IServerCommandVisitor &visitor_)
{
	visitor_.visit(*this);
}