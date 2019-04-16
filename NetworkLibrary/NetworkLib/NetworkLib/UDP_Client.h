#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include "UDP_Controller.h"


class UDP_Client : public UDPController
{
public:
	UDP_Client();
	~UDP_Client();

	bool UDPCreateClient(std::string &ip, int32_t remotePort, int32_t localPort);
	bool UDPClientSend(const std::string &str);
	const char* UDPClientReceive();
};

#endif
