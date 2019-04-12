#ifndef UDP_CONTROLLER_H
#define UDP_CONTROLLER_H

#include "Network_Controller.h"

#include <string>
#include <windows.h>

class UDPController : public NetworkController
{
private:
	UDPsocket ourSocket;

public:
	UDPpacket *packet;
	bool quit;

	//
	UDPController() : quit(false) {}

	//
	~UDPController()
	{
		SDLNet_FreePacket(packet);
		SDLNet_Quit();
	}
	//
	bool Init(const std::string &ip_, int32_t remotePort, int32_t localPort)
	{
		std::cout << "Connecting to \n\tIP : " << ip_ << "\n\tPort : " << remotePort << std::endl;
		std::cout << "Local port : " << localPort << "\n\n";

		// Initialize SDL_net
		if (!InitSDL_Net())
			return false;

		if (!OpenPort(localPort))
			return false;

		if (!SetIPAndPort(ip_, remotePort))
			return false;

		if (!CreatePacket(65536))
			return false;

		/* bind server address to channel 0 */
		if (SDLNet_UDP_Bind(ourSocket, 0, &this->ip) == -1)
		{
			printf("SDLNet_UDP_Bind: %s\n", SDLNet_GetError());
			return false;
		}

		return true;
	}

	bool InitServer(int32_t remotePort, int32_t localPort) {
		std::cout << "connecting to port" << remotePort << std::endl;
		std::cout << "Local port : " << localPort << "\n\n";

		// Initialize SDL_net
		if (!InitSDL_Net())
			return false;

		if (!OpenPort(localPort))
			return false;

		if (!SetPort(remotePort))
			return false;

		if (!CreatePacket(65536))
			return false;

		SDLNet_UDP_Unbind(ourSocket, 0);

		return true;
	}
	bool InitSDL_Net()
	{
		std::cout << "Initializing SDL_net...\n";

		if (SDLNet_Init() == -1)
		{
			std::cout << "\tSDLNet_Init failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}

	//
	bool CreatePacket(int32_t packetSize)
	{
		std::cout << "Creating packet with size " << packetSize << "...\n";

		// Allocate memory for the packet
		packet = SDLNet_AllocPacket(packetSize);

		if (packet == nullptr)
		{
			std::cout << "\tSDLNet_AllocPacket failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		// Set the destination host and port
		// We got these from calling SetIPAndPort()
		packet->address.host = ip.host;
		packet->address.port = ip.port;

		std::cout << "\tSuccess!\n\n";
		return true;
	}

	//
	bool OpenPort(int32_t port)
	{
		std::cout << "Opening port " << port << "...\n";

		// Sets our sovket with our local port
		ourSocket = SDLNet_UDP_Open(port);

		if (ourSocket == nullptr)
		{
			std::cout << "\tSDLNet_UDP_Open failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}

	//
	bool SetIPAndPort(const std::string &ip_, uint16_t port)
	{
		std::cout << "Setting IP ( " << ip_ << " ) " << "and port ( " << port << " )\n";

		// Set IP and port number with correct endianess
		if (SDLNet_ResolveHost(&this->ip, ip_.c_str(), port) == -1)
		{
			std::cout << "\tSDLNet_ResolveHost failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}

	//
	bool SetPort(uint16_t port)
	{
		std::cout << "Setting up port ( " << port << " )\n";

		// Set IP and port number with correct endianess
		if (SDLNet_ResolveHost(&this->ip, NULL, port) == -1)
		{
			std::cout << "\tSDLNet_ResolveHost failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}

	// Send data. 
	bool Send(const std::string &str)
	{
		// Set the data
		// UDPPacket::data is an Uint8, which is similar to char*
		// This means we can't set it directly.
		//
		// std::stringstreams let us add any data to it using << ( like std::cout ) 
		// We can extract any data from a std::stringstream using >> ( like std::cin )
		//
		//str

		memcpy(packet->data, str.c_str(), str.length());
		packet->len = str.length();

		// Send
		// SDLNet_UDP_Send returns number of packets sent. 0 means error
		//packet->channel = -1;
		if (SDLNet_UDP_Send(ourSocket, -1, packet) == 0)
		{
			std::cout << "\tSDLNet_UDP_Send failed : " << SDLNet_GetError() << "\n"
				<< "==========================================================================================================\n";
			//msg.resize(0);
			return false;
		}
		std::cout << "sent to: " << packet->address.host << "\n";
		std::cout << "length is: " << packet->len << "\n";
	}

	//
	const char* recievedData() {
		// Check to see if there is a packet wauting for us...
		if (SDLNet_UDP_Recv(ourSocket, packet))
		{
			return reinterpret_cast<char*>(packet->data);
		}

		return NULL;
	}

	//
	inline bool WasQuit()
	{
		return quit;
	}

};

#endif //UDP_CONTROLLER_H
