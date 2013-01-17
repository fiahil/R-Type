
#include	<iostream> //
#include	<sstream>

#include	"EndPoint.h"

namespace Net
{

EndPoint::EndPoint(unsigned int ip, unsigned short port)
	: ip_(ip), port_(port)
{
	convertIp_(this->ip_);
}

EndPoint::EndPoint(const std::string& ipStr, unsigned short port)
	: ipStr_(ipStr), port_(port)
{
	convertIp_(this->ipStr_);
}


EndPoint::EndPoint(unsigned short port)
	: port_(port)
{
	this->ip_ = 0;
}

EndPoint::EndPoint(const EndPoint& e)
	: ip_(e.ip_), ipStr_(e.ipStr_), port_(e.port_)
{
}

EndPoint& EndPoint::operator=(const EndPoint& e)
{
	if (&e != this) {
		this->ip_ = e.ip_;
		this->ipStr_ = e.ipStr_;
		this->port_ = e.port_;
	}
	return (*this);
}

EndPoint::~EndPoint()
{
}

void EndPoint::convertIp_(const std::string& ipStr)
{
	if (ipStr.empty()) {
		this->ip_ = 0;
		return;
	}
	union EndPoint::u_ip uIp;
	std::stringstream ss;
	unsigned int b1, b2, b3, b4;
	char p;
	ss << ipStr;
	ss >> b1 >> p >> b2 >> p >> b3 >> p >> b4;
	uIp.byte[3] = b1;
	uIp.byte[2] = b2;
	uIp.byte[1] = b3;
	uIp.byte[0] = b4;
	this->ip_ = uIp.ip;
}

void EndPoint::convertIp_(unsigned int ip)
{
	union EndPoint::u_ip uIp;
	uIp.ip = ip;
	unsigned int b1, b2, b3, b4;
	b1 = uIp.byte[3];
	b2 = uIp.byte[2];
	b3 = uIp.byte[1];
	b4 = uIp.byte[0];
	std::stringstream ss;
	ss << b1 << "." << b2 << "." << b3 << "." << b4;
	this->ipStr_ = ss.str();
}

unsigned int EndPoint::getIp() const
{
	return (this->ip_);
}

const std::string& EndPoint::getIpStr() const
{
	return (this->ipStr_);
}

unsigned short EndPoint::getPort() const
{
	return (this->port_);
}

}			//namespace Net
