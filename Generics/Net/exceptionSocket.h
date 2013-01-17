
#pragma once

#include	<string>
#include	<exception>

namespace Net
{

class ErrorInit : public std::exception
{
private:
	std::string msg_;

public:
	ErrorInit(const std::string& msg) : msg_(msg) {}
	~ErrorInit() throw() {}
	const char* what() const throw() { return (this->msg_.c_str()); }
};

class ErrorInOut : public std::exception
{
private:
	std::string msg_;

public:
	ErrorInOut(const std::string& msg) : msg_(msg) {}
	~ErrorInOut() throw() {}
	const char* what() const throw() { return (this->msg_.c_str()); }
};

}		// namespace Net
