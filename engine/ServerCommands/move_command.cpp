#include "pav_pch.h"
#include "move_command.h"


void pav::MoveCommand::Execute(DataManager *manager_)
{

}

void pav::MoveCommand::Accept(IServerCommandVisitor &visitor_)
{
	visitor_.Visit(this);
}