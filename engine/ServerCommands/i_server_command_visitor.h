#ifndef I_SERVER_COMMAND_VISITOR_H
#define I_SERVER_COMMAND_VISITOR_H

#include "invoke_skill_command.h"
#include "Health_Mod_Command.h"

namespace pav{
class IServerCommandVisitor
{
public:
	virtual void Visit(InvokeSkillCommand *command_) = 0;
	virtual void Visit(HealthModCommand *command_) = 0;

};

#endif;
}