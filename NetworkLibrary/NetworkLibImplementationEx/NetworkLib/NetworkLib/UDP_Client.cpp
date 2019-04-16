#include "UDP_Client.h"



UDP_Client::UDP_Client()
{
}


UDP_Client::~UDP_Client()
{
}

bool UDP_Client::UDPCreateClient(std::string &ip, int32_t remotePort, int32_t localPort)
{
	return Init(ip, remotePort, localPort);
}

bool UDP_Client::UDPClientSend(const std::string & str)
{
	return Send(str);
}

const char * UDP_Client::UDPClientReceive()
{
	return recievedData();
}
