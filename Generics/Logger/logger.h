
#pragma once

#include <iostream>
#include <time.h>

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

//Logger	DEBUG(std::cout, "[Debug]");
//Logger	LOG(std::cerr, "[Log]");

template <class T>
std::ostream& operator<<(Logger& logger, T o)
{
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

#ifndef NODEBBUG
	logger.getStream() << logger.getLabel() << asctime (timeinfo) << o;
#endif
	return logger.getStream();
}
