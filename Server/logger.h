
#include <iostream>

class Logger
{
	std::ostream&	oss_;
	std::string		label_;

public:
	Logger(std::ostream&, std::string const&);
	~Logger();
	template <class T> operator<<(Logger&, T o);

};

Logger::Logger(std::ostream& stream, std::string const& label) : oss_(stream), label_(label)
{
		
}

Logger::~Logger()
{
}

template <class T>
Logger::operator<<(Logger& logger, T o)
{
	this->oss_ << this->label_ << " " << o << std::endl;
}