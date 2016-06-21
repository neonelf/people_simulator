#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>
#include <sstream>

enum LoggingChannels
{
	CHANNEL_TRACE = 0x01
};

class Logger
{
public:
	Logger() {}
	~Logger() {}

	void Log(int Channel, const std::string &strMessage);
};

extern Logger& getGlobalLogger(); //defined in main CPP file

#endif //__LOGGER_H__
