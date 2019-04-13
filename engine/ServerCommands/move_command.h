#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include "i_Server_Command.h"
#include "Data_Manager.h"

namespace pav{



class MoveCommand : public IServerCommand
{
	
private:
	glm::vec3 direction;

public:

	 void Execute(class DataManager *manager_);

	 void Accept(class IServerCommandVisitor &visitor_);

};

}
#endif