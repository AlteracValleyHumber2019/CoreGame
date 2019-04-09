#ifndef INVOKE_SKILL_COMMAND_H
#define INVOKE_SKILL_COMMAND_H

#include "i_Server_Command.h"
#include "data_manager.h"


namespace pav{



class InvokeSkillCommand : public IServerCommand
{
public:

	class ISkill *skill;

	void Execute(class DataManager *manager_) ;
	void Accept(class IServerCommandVisitor &visitor_);

};
}
#endif;

