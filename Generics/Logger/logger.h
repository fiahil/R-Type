
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

Logger::Logger(std::ostream& stream, std::string const& label) : oss_(stream), label_(label)
{
		
}

Logger::~Logger()
{
}

std::ostream&	Logger::getStream()
{
	return this->oss_;
}

std::string		Logger::getLabel() const
{
	return this->label_;
}

template <class T>
std::ostream& operator<<(Logger& logger, T o)
{
	logger.getStream() << logger.getLabel() << " " << o;
	return logger.getStream();
}