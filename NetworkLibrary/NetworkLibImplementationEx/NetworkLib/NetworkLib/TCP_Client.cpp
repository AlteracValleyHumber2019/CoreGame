#include "TCP_Client.h"


TCP_Client::TCP_Client() : bIsConnected(false)
{

}


TCP_Client::~TCP_Client()
{
	// Mike: Close the server connection
	SDLNet_TCP_Close(server_TCPsocket);

	// Mike: Quit out of both SDLnet and SDL
	SDLNet_Quit();
}

bool TCP_Client::InitializeClient()
{
	// Mike: Initialize SDL_net - return false if it fails, printing out an error message
	if (SDLNet_Init() < 0)
	{
		std::cout << "SDLNet_INIT failed, aborting client process" << std::endl;
		return false;
	}

	// Mike: If everything intializes properly, return true
	std::cout << "SDL_net was successfully initialized" << std::endl;
	return true;
}

bool TCP_Client::PrepareForConnection(const char* host_address_, int portToConnect_)
{
	// Mike: Set the port that this client will try and connec to 
	port_client = portToConnect_;

	/* Mike: "SDLNet_ResolveHost" will setup the IP address of the client to be prepared to connect to a host
	This is done by passing the IP address of the host to the function (second parameter)
	NOTE: right now, this client will try and connect to the same PC that it is running on, 127.0.0.1 is "me"

	@param 1: The ip address
	@param 2: The host value of the server.
	@param 3: The port we are connecting to (There are 6500 ports we can connect to)

	Return: The function returns -1 if it fails*/
	if (SDLNet_ResolveHost(&ip, host_address_, port_client) == -1)
	{
		std::cout << "SDLNet_ResolveHost() failed, aborting client process" << std::endl;
		return false;
	}

	// Mike: if the IP address was setup correctly and nothing went wrong, then return true
	std::cout << "Client successfully prepared for connections" << std::endl;
	return true;
}

bool TCP_Client::ConnectToServer()
{
	/* Mike: Connections to hosts are done via SDLNet_TCP_Open (which takes in an IP address).

	@param: the IPaddress contans the IP and port we want to connect to. We’ll use the one we got from SDLNet_ResolveHost

	Return: For clients: this return is the TCP socket of the server, used for sending and receiving data */
	client_TCPsocket = SDLNet_TCP_Open(&ip);

	// Mike: Check if the socket of the server is null, if it isn't then it worked
	if (client_TCPsocket == nullptr)
	{
		std::cout << "Failed to connect to port : " << port_client << " \n\tError : " << SDLNet_GetError() << std::endl;
		return false;
	}

	// Mike: If the client connected properly, return true
	std::cout << "Client successfully connected to server" << std::endl;
	return true;
}

void TCP_Client::Send(std::string message_)
{
	// Mike: Convert the std::string message into a const char*
	const char* charMessage = message_.c_str();

	// Mike: Convert the message into a void* for sending 
	void* data = const_cast<char*>(charMessage);

	// Mike: Get the length of the message to send via static_cast
	int messageLength = static_cast<int> (message_.length());

	/* Mike: Call the function SDLNet_TCP_Send, which returns the number of bytes to be sent, and save this value as bytesSent

	@params: The TCP socket where data will be sent
	@params: The data to send (this is a pointer to ANYTHING)
	@params: The length of the data

	Return: The number of bytes that were sent. If the number sent is less than the size, then there was a problem. */
	int bytesSent = SDLNet_TCP_Send(client_TCPsocket, data, messageLength);

	// Mike: Check that the size of the message that was sent was correct
	if (bytesSent < messageLength)
	{
		std::cout << "Error sending data! Data sent was smaller than expected" << std::endl;
	}
}

const char* TCP_Client::ReceiveMessage()
{
	// Mike: Set the size of the buffer
	const int bufferSize = 1000;

	// Mike: Set aside a char array that can be used to accept information
	char buffer[bufferSize];

	// Mike: Make sure that the buffer is empty
	memset(buffer, 0, bufferSize);

	/* Mike: Try and receive data via SDLNet_TCP_Recv and store the return value

	@params: The TCP socket where data will be accepted
	@params: The data received
	@params: The max length of the data to be received

	Return: The number of data received. If this is less than 0, an error occured. */
	int byteCount = SDLNet_TCP_Recv(client_TCPsocket, buffer, bufferSize);

	// Mike: Check if the size of received data is 0
	if (byteCount > 0)
	{
		// Mike: Assign the final character in buffer to 0 which means "end the string"
		buffer[byteCount] = '\0';
		std::cout << "Information Received: " << buffer << std::endl;
		return buffer;
	}

	// Mike: If nothing was received, then return 0
	return nullptr;
}

void TCP_Client::UpdateClient()
{

}
