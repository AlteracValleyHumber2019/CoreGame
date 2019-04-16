#ifndef TCP_SERVER_H
#define TCP_SERVER_H

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

	/* Mike: This function will initialize SDL for the server
	Return: true on success and false if something goes wrong */
	bool InitializeServer();

	/* Mike: This function will setup the ip of this server using the port for connections from clients
	Return: true on success and false if something goes wrong */
	bool PrepareForConnection(int portToConnect_);

	/* Mike: Send messages to a connected client */
	void SendMessage(std::string message_);

	/* Mike: Receive messages to a connected client, will return 0 if no message received and 1 if something is accepted */
	const char* ReceiveMessage();

	int UpdateServer();

private:
	//The IP address of this server
	IPaddress ip;

	//The port that will be available to the client
	int port_server;

	//Simple word to send to the client
	const char* buffer;

	//The socket for the TCP connection for the server (note the TCPsocket is the name of a struct)
	TCPsocket server_TCPsocket;

	//Create the socket for the client but don't set it yet
	TCPsocket client_TCPsocket;
};


#endif // !TCP_SERVER_H
