#ifndef I_SERVER_COMMAND_H
#define I_SERVER_COMMAND_H

namespace pav{


class IServerCommand
{

protected: 
	unsigned int playerID;

public:

	virtual void Execute(/*ServerManager manager_*/) = 0;

	virtual void Accept(class IServerCommandVisitor &visitor_) = 0;

	unsigned int GetPlayerID();
	

};
#endif;


}
