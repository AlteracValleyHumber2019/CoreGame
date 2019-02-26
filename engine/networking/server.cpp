#include <SDL.h>

#include <cstring>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <thread>

#include "TCP_Server.h"


int CreateServer(void* data)
{
	std::shared_ptr<TCP_Server> server = std::make_shared<TCP_Server>();
	
	if (server->InitializeServer())
	{
		server->UpdateServer();
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int data = 1;
	SDL_Thread* threadID = SDL_CreateThread(CreateServer, "Server_Test", (void*)data);
	
	while (1)
	{
		std::cin.get();
		running = false;
	}

	SDL_WaitThread(threadID, NULL);
	return 0;
	
	return 0;
}