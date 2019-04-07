#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "ServerCommands/i_Server_Command_visitor.h"
#include "ServerCommands/i_Server_Command.h"
#include <iostream>

namespace pav{
	class IServerCommand;
	class HealthModCommand;
	class MoveCommand;
	class IServerCommandVisitor;

	using namespace std;

class DataManager : public IServerCommandVisitor
{
private: 
	bool lock;
	// Gamestate currentGameState;
	//GameState nextGameState;
public:
	void SendGameState(/*GameState PackadgedGameState_*/); 
	void SendCommand(IServerCommand command_, DataManager manager_);

	void Visit(InvokeSkillCommand *command_) ; 
	void Visit(HealthModCommand *command_);
	void Visit(MoveCommand *command_);
};
#endif;
}

