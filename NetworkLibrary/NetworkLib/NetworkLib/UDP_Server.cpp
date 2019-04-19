#include "UDP_Server.h"



UDP_Server::UDP_Server()
{

}


UDP_Server::~UDP_Server()
{
}

bool UDP_Server::UDPCreateServer(int32_t remotePort, int32_t localPort)
{
	return InitServer(remotePort, localPort);
}

bool UDP_Server::UDPServerSend(const std::string & str)
{
	return Send(str);
}

const char * UDP_Server::UDPServerReceive()
{
	return recievedData();
}
