
#pragma once

#include <iostream>
#include <ctime>

class Logger
{
	std::ostream&	oss_;
	std::string		label_;

public:
	Logger(std::ostream&, std::string const&);
	~Logger();
	std::ostream&	getStream();
	std::string		getLabel() const;
};

extern Logger	DEBUG;
extern Logger	LOG;

template <class T>
std::ostream& operator<<(Logger& logger, T o)
{
#ifndef NDEBUG
	/*
	time_t rawtime;
	tm timeinfo;
	char timer[4096];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	asctime_s(timer, &timeinfo);
	*/

	logger.getStream() << logger.getLabel() << "\t" << o;
#else
	(void)o;
#endif
	return logger.getStream();
}
