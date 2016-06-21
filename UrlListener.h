#ifndef __URLLISTENER_H__
#define __URLLISTENER_H__


class UrlListener
{
public:
	UrlListener();
	~UrlListener();

	bool StartListening(int port);

protected:
	int m_ListenPortNumber;
	int m_Socket;
};






#endif //__URLLISTENER_H__
