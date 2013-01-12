
#include <iostream>

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

template <class T>
std::ostream& operator<<(Logger& logger, T o)
{
	logger.getStream() << logger.getLabel() << " " << o;
	return logger.getStream();
}