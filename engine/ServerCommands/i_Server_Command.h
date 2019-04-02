#ifndef I_SERVER_COMMAND_H
#define I_SERVER_COMMAND_H
namespace pav{


class IServerCommand
{

protected: 
	unsigned int playerID;

public:

	virtual void Execute(/*ServerManager manager_*/) = 0;

	void Accept(/*DataManager *Manager_*/);

	unsigned int GetPlayerID()
	{
		return playerID;
	}
	

};
#endif;

}
