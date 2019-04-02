#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "i_Server_Command_visitor.h"
#include "i_Server_Command.h"
namespace pav{
class DataManager : public IServerCommandVisitor
{
private: 
	bool lock;
	// Gamestate currentGameState;
	//GameState nextGameState;
public:
	void SendGameState(/*GameState PackadgedGameState_*/);
//	Gamestate ReceiveGameState();
	void SendCommand(IServerCommand);
	void Visit(InvokeSkillCommand *command_) override;
	void Visit(HealthModCommand *command_) override;
	
};
#endif;
}

