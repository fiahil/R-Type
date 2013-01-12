
#include	"logger.h"

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

Logger	DEBUG(std::cout, "[Debug]");
Logger	LOG(std::cerr, "[Log]");

