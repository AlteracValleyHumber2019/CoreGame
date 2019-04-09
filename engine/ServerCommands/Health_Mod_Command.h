#ifndef HEALTH_MOD_COMMAND_H
#define HEALTH_MOD_COMMAND_H

#include "i_Server_Command.h"
#include "Data_Manager.h"

namespace pav{
	

class HealthModCommand : public IServerCommand
{

private:
	float amount;
public:
	void Execute(DataManager* manager_ );
	void Accept(class IServerCommandVisitor &visitor_);
};


}
#endif