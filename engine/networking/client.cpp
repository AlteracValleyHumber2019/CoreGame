//#include <iostream>
//#include <SDL.h>
//#include <SDL_net.h>
//#include <cstring>
//
//int main(int argc, char* argv[])
//{
//	//Initialize SDL and SDL_net
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDLNet_Init();
//
//	//The IP address of this client
//	IPaddress ip;
//
//	/* Populate the ip address structure created above.
//	Parameters:
//	1) The ip address
//	2) The host value is this computers loop back IP address
//	3) The port we are connecting to (There are 6500 ports we can connect to)*/
//	SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
//
//	//Create the socket for the client but don't set it yet
//	TCPsocket clientLocal = SDLNet_TCP_Open(&ip);
//
//	//int i = 0;
//	
//	//The array of chars that will be used to accept something
//	const char* buffer[100];
//
//	//if (SDLNet_SocketReady(clientLocal) > 0)
//	{
//		//First spot of free space in the buffer
//		int end = 0;
//
//		while (1)
//		{
//			//Append the new data at the end of the previous remaining data
//			int received = SDLNet_TCP_Recv(clientLocal, buffer, 5000 - end);
//
//			end = end + received;
//			
//			int index = 0;
//
//			while (1)
//			{
//				// detect a message at the start of the buffer
//
//				while (index < end && buffer[index] != "\0")
//				{
//					index = index + 1;
//				}
//
//				//Failed to find a message, wait for more data
//				if (index >= end)
//				{
//					break;
//				}
//			}
//
//			// 'index' points to the '\0', the last byte of the message
//			int length = index + 1;
//
//
//			printf("Found a message of length %d\n", length);
//			std::cout << buffer << std::endl;
//
//			memmove(buffer, buffer + length, end - length);
//			end = end - length;
//		}
//	}
//
//	
//	
//
//	//Close the client socket
//	SDLNet_TCP_Close(clientLocal);
//
//	//Quit out of both SDLnet and SDL
//	SDLNet_Quit();
//	SDL_Quit();
//
//	getchar();
//
//	return 0;
//}