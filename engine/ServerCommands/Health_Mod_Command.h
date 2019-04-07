#ifndef HEALTH_MOD_COMMAND_H
#define HEALTH_MOD_COMMAND_H

#include "i_Server_Command.h"

namespace pav{

class HealthModCommand : public IServerCommand
{
private:
	float amount;
public:
	void Execute(/*DataManager manager_ */);
	void Accept(IServerCommandVisitor &visitor_);
};

#endif;
}
