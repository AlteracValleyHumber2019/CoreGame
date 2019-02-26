#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <cstring>

int main(int argc, char* argv[])
{
	//Initialize SDL and SDL_net
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	//The IP address of this client
	IPaddress ip;

	/* Populate the ip address structure created above.
	Parameters:
	1) The ip address
	2) The host value is this computers loop back IP address
	3) The port we are connecting to (There are 6500 ports we can connect to)*/
	SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);

	//Create the socket for the client but don't set it yet
	TCPsocket clientLocal = SDLNet_TCP_Open(&ip);

	int i = 0;
	while (i < 1000)
	{
		//The array of chars that will be used to accept something
		char text[100];

		//Use the TCP receive function which will accept something send via its partner class "SDLNet_TCP_Send"
		SDLNet_TCP_Recv(clientLocal, text, 100);

		//Print to the console whatever was received
		std::cout << text << std::endl;

		i++;
	}


	//Close the client socket
	SDLNet_TCP_Close(clientLocal);

	//Quit out of both SDLnet and SDL
	SDLNet_Quit();
	SDL_Quit();

	getchar();

	return 0;
}