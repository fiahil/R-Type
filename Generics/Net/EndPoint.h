
#pragma once

#include	<string>

namespace Net
{

class EndPoint
{
private:
	union u_ip
	{
		unsigned char byte[4];
		unsigned int ip;
	};

	unsigned int ip_;
	std::string ipStr_;
	unsigned short port_;

	void convertIp_(const std::string&);
	void convertIp_(unsigned int);

public:
	EndPoint(unsigned int, unsigned short);
	EndPoint(const std::string&, unsigned short);
	EndPoint(const EndPoint&);
	EndPoint(unsigned short);
	EndPoint& operator=(const EndPoint&);
	~EndPoint();
	unsigned int getIp() const;
	const std::string& getIpStr() const;
	unsigned short getPort() const;
};

}			// namespace Net