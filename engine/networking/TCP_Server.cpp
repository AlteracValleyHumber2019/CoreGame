#include "TCP_Server.h"

using namespace std::literals::chrono_literals;

TCP_Server::TCP_Server()
{
	//Simple word to send to the client
	buffer = "Hello Client";
}


TCP_Server::~TCP_Server()
{
	//Close the server connection
	SDLNet_TCP_Close(server);

	//Quit out of both SDLnet and SDL
	SDLNet_Quit();
	SDL_Quit();
}

bool TCP_Server::InitializeServer()
{
	//Initialize SDL and SDL_net
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL_INIT failed, aborting process";
		return false;;
	}

	if (SDLNet_Init() < 0)
	{
		std::cout << "SDLNet_INIT failed, aborting process";
		return false;
	}

	/* Populate the ip address structure created above.
	@param 1 The ip address
	@param 2 The host value is null as this is the server. Can also connect to external sources, like google
	@param 3 The port we are connecting to (There are 6500 ports we can connect to)
	
	Note: The function returns -1 if it fails*/
	if (SDLNet_ResolveHost(&ip, NULL, 1234) == -1)
	{
		std::cout << "SDLNet_ResolveHost() failed, aborting process";
		return false;
	}

	//Create the socket for the TCP connection for the server (note the TCPsocket is the name of a struct)
	server = SDLNet_TCP_Open(&ip);

	if (!server)
	{
		std::cout << "server is not valid, aborting process";
		return false;
	}
	
	std::cout << "Server creation was successful";

	running = true;
	return true;
}

void TCP_Server::UpdateServer()
{
	//Core game loop that will loop until something running is set to false
	while (running)
	{
		//If someone tries to connect to this server, we can get the socket of the server for the client
		client = SDLNet_TCP_Accept(server);

		//Check if the client is valid (not null) that means that something has connect to it
		if (client)
		{
			/* This is where the communication happens - we can use TCP_Send to send information
			Parameters:
			1) The socket we are sending data to
			2) This is a void pointer for any data type we want (in this case it will be text)
			3) The length of what we are sending (using strlen = string length) */
			//SDLNet_TCP_Send(client, text, strlen(text) + 1);

			//Close the connection to the client
			//SDLNet_TCP_Close(client);
			std::cout << "Client successfully connected to this server " << std::endl;
			break;
		}
	}

	while (client)
	{
		SDLNet_TCP_Send(client, buffer, strlen(buffer) + 1);
		std::this_thread::sleep_for(0.1s);
	}
}
