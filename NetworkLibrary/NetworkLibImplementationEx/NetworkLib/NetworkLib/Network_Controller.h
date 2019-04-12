#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROLLER_H

#include <SDL_net.h>
#include <iostream>
#include <cstring>

/* Parent class to both UDP and TCP client classes */
class NetworkController
{

protected:
	//The IP address of the server
	IPaddress ip;

	//Add Interface methods here 
};

#endif
