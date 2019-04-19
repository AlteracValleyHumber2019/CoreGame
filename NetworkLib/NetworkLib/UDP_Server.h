#ifndef UDP_SERVER_H
#define UDP_SERVER_H


#include "UDP_Controller.h"

class UDP_Server : public UDPController
{
public:
	UDP_Server();
	~UDP_Server();

	bool UDPCreateServer(int32_t remotePort, int32_t localPort);
	bool UDPServerSend(const std::string &str);
	const char* UDPServerReceive();

};

#endif // !15