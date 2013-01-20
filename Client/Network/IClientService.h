
#ifndef _ICLIENTSERVICE_H_
#define _ICLIENTSERVICE_H_

class TCPPacket;

class UDPPacket;

class	ITCPClientService
{
public:
  virtual ~ITCPClientService() {}
  virtual void recvData() = 0;
  virtual void sendData(TCPPacket*) = 0;
};

class	IUDPClientService
{
public:
  virtual ~IUDPClientService() {}
  virtual void recvData() = 0;
  virtual void sendData(UDPPacket*) = 0;
};

#endif /* !_ICLIENTSERVICE_H_ */
