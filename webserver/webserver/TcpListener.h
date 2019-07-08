#pragma once
#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <sstream>

#pragma comment (lib, "ws2_32.lib")

// abstract class 

class TcpListener
{
public: 

	TcpListener(const char* ipAddress, int port) :
		m_ipAddress(ipAddress), m_port(port) { }

	// intialize the listener
	int init();
	
	// Run the listener
	int run();
protected:
	// Handling client connection 
	virtual void onClientConnected(int clientSocket);

	// Handling client disconnection 
	virtual void onClientDisconnected(int clientSocket);

	// Handling when a message is received from a client
	virtual void onMessageReceived(int clientSocket, const char* msg, int length);

	// Sending a message to a client
	void sendToClient(int clientSocket, const char* msg, int length);

	// Broadcast a message from a client
	void breadcastToClients(int sendingClient, const char* msg, int length);

private:
	const char*			m_ipAddress;				// IP Address server will run on 
	int					m_port;						// Port # for the web server
	int					m_socket;					// Internal socket FD for the listening socket 
	fd_set				m_master;						// Master file descriptor set
};