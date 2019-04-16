#include "TCP_Server.h"

TCP_Server::TCP_Server()
{
	// Mike: Simple word to send to the client
	buffer = "Hello Client";
}


TCP_Server::~TCP_Server()
{
	// Mike: Close the server connection
	SDLNet_TCP_Close(server_TCPsocket);

	// Mike: Quit out of both SDLnet and SDL
	SDLNet_Quit();
}

bool TCP_Server::InitializeServer()
{
	// Mike: Initialize SDL_net - return false if it fails, printing out an error message
	if (SDLNet_Init() < 0)
	{
		std::cout << "SDLNet_INIT failed, aborting server process";
		return false;
	}

	// Mike: If everything goes smoothly, print success message and return true
	std::cout << "SDL_net was successfully initialized" << std::endl;
	return true;
}

bool TCP_Server::PrepareForConnection(int portToConnect_)
{
	// Mike: Set the port that this server will have open for connections
	port_server = portToConnect_;

	/* Mike: "SDLNet_ResolveHost" will setup the IP address of the server to be prepared to listen for clients, and not connect to a host
	This is done by passing NULL as the host IP (second parameter), which will set the IP to something called INADDR_NONE

	@param 1: The ip address
	@param 2: The host value is null as this is the server. Can also connect to external sources, like google
	@param 3: The port we are connecting to (There are 6500 ports we can connect to)

	Return: The function returns -1 if it fails*/
	if (SDLNet_ResolveHost(&ip, NULL, port_server) == -1)
	{
		std::cout << "SDLNet_ResolveHost() failed and no port was opened, aborting server process" << std::endl;
		return false;
	}

	/* Mike: Setup the socket for the TCP connection for this server (note the TCPsocket is the name of a struct)
	The server TCP socket will be used for listening and as such, won't have a specific IP address (set in resolve host)

	 @param: the IPaddress contans the IP (null) and port (1234) we want to connect to. We’ll use the one we got from SDLNet_ResolveHost

	Return: This is the TCP socket used for listening for client connections*/
	server_TCPsocket = SDLNet_TCP_Open(&ip);

	// Mike: Check if the socket is valid
	if (!server_TCPsocket)
	{
		std::cout << "server is not valid, aborting process" << std::endl;
		return false;
	}

	// Mike: If the server was setup properly, print a success message and return true
	std::cout << "Server creation was successful" << std::endl;
	return true;
}

void TCP_Server::SendMessage(std::string message_)
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

const char* TCP_Server::ReceiveMessage()
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

int TCP_Server::UpdateServer()
{
	/* Mike: If someone tries to connect to this server, we can get the socket of the server for the client

	@params: The socket of this server is passed as it is the socket setup for receiving connections

	Return: The socket of the client is returned to us */
	client_TCPsocket = SDLNet_TCP_Accept(server_TCPsocket);

	// Mike: Check if the client is valid (not null) that means that something has connect to it
	if (client_TCPsocket)
	{
		std::cout << "Client successfully connected to this server!" << std::endl;

		if (ReceiveMessage() == 0)
		{
			std::cout << "No information received!" << std::endl;
		}
		else
		{
			SendMessage("Got your message: Hi Client!");
			return 1;
		}
	}
	return 0;
}


