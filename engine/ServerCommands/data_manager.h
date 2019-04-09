#pragma once

#include "invoke_skill_command.h"
#include "Health_Mod_Command.h"
#include "move_command.h"

namespace pav{

	class InvokeSkillCommand;
	class HealthModCommand;
	class MoveCommand;

	class IServerCommandVisitor
	{

	public:
		virtual void Visit(InvokeSkillCommand *command_) = 0;
		virtual void Visit(HealthModCommand *command_) = 0;
		virtual void Visit(MoveCommand *command_) = 0;


	};

class DataManager : public IServerCommandVisitor
{
	void SendGameState(/*GameState PackadgedGameState_*/);
	void SendCommand(IServerCommand *command_, DataManager manager_);


	void Visit(InvokeSkillCommand *command_);
	void Visit(HealthModCommand *command_);
	void Visit(MoveCommand *command_);

public:

};

}
