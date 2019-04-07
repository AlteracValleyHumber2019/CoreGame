#include "pav_pch.h"
#include "data_manager.h"
#include <iostream>

void pav::DataManager::SendCommand(IServerCommand command_, DataManager manager_)
{
	command_.Execute(/*manager_*/);
}

void pav::DataManager::Visit(HealthModCommand *command_)
{
	printf("Visit InvokeSkillCommand");
	command_.Accept();
}



void pav::DataManager::Visit(InvokeSkillCommand *command_)
{
	printf("Visit InvokeSkillCommand");
	command_.Accept();
}

void pav::DataManger::Visit(MoveCommand *command_)
{
	printf("Visit MoveCommand");
	command_.Accept();
}
