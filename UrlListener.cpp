#include "UrlListener.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

UrlListener::UrlListener()
{
	m_Socket = -1;
}

UrlListener::~UrlListener()
{
}


bool UrlListener::StartListening(int port)
{
	//create socket
	m_Socket  = socket(AF_INET, SOCK_STREAM, 0);
	if (m_Socket == -1)
	{
		perror("ERROR opening Socket");
		return false;
	}
	//fill in socket address
	struct sockaddr_in addr;
	::memset((void*)&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//bind to port
	if (-1 ==  bind(m_Socket, (sockaddr*)&addr, sizeof(addr)))
	{
		perror("ERROR binding socket");
		::close(m_Socket);
		m_Socket = -1;
		return false;
	}
	
	//listen
	if (-1 == listen(m_Socket, 5))
	{
		perror("ERROR on listen");
		::close(m_Socket);
		m_Socket = -1;
		return false;
	}
}
