#pragma once

namespace pav{
//	class IServerCommandVisitor;

class IServerCommand
{

protected:
	unsigned int playerID;

public:

	virtual void Execute(class DataManager* manager_) = 0;

	virtual void Accept(class IServerCommandVisitor &visitor_) = 0;

	//unsigned int GetPlayerID();
};

}