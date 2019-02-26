#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <SDL.h>
#include <SDL_net.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <thread>

static bool running;

class TCP_Server
{
public:
	TCP_Server();
	~TCP_Server();

	bool InitializeServer();
	void UpdateServer();

	//The IP address of this server
	IPaddress ip;

	//Simple word to send to the client
	const char* buffer;

	//The socket for the TCP connection for the server (note the TCPsocket is the name of a struct)
	TCPsocket server;

	//Create the socket for the client but don't set it yet
	TCPsocket client;
private:
};


#endif // !TCP_SERVER_H