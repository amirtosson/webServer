#pragma once
#include "TcpListener.h"


class MultiClientChat :public TcpListener
{
public:
	MultiClientChat(const char* ipAddress, int port) :
		TcpListener(ipAddress, port) { }
	
protected:
	// Handling client connection 
	virtual void onClientConnected(int clientSocket);

	// Handling client disconnection 
	virtual void onClientDisconnected(int clientSocket);

	// Handling when a message is received from a client
	virtual void onMessageReceived(int clientSocket, const char* msg, int length);

};

