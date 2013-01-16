#ifndef	_PACKMAN_HPP_
#define _PACKMAN_HPP_

#include "logger.h"

#include <map>
#include "SCRequest.h"
#include "CSRequest.h"

class	PackMan
{
  template<typename S>
  static void* MemSet(S* dest, std::size_t c)
  {
    unsigned char *Tdest = reinterpret_cast<unsigned char*>(dest);
    unsigned char const *Tc = reinterpret_cast<unsigned char const*>(dest) + c;

    while (Tdest != Tc)
      *(Tdest++) = 0;
    return (dest);
  }

public:
  template<typename S, typename U>
  static void* Memcpy(U* dest, S* src, std::size_t c)
  {
    unsigned char const *Tsrc = reinterpret_cast<unsigned char const*>(src);
    unsigned char *Tdest = reinterpret_cast<unsigned char *>(dest);
    unsigned char const *Tc = reinterpret_cast<unsigned char const*>(src) + c;

    PackMan::MemSet(Tdest, c);
    while (Tsrc != Tc)
      *(Tdest++) = *(Tsrc++);

    return (dest);
  }

  static std::map<eRequestType, IRequest* (*)(TCPPacket*)>	request_tab;

  static TCPPacket*	pack(IRequest* a)
  {
    TCPPacket*	pack = new TCPPacket();
    std::string	val = a->toString();
    
    pack->H.type = a->getType();
    PackMan::Memcpy(pack->B, val.data(), val.size());
    pack->H.size = val.size() + (2 * sizeof(int16_t));

    return (pack);
  }

  template <class T>
  static IRequest*	unpack_T(TCPPacket *pack)
  {
	DEBUG << "Unpacking TCP Packet : " << std::endl;
    DEBUG << " - " << pack->B << std::endl;
    DEBUG << " - " << pack->H.size << std::endl;
    std::string s(pack->B, pack->H.size - sizeof(TCPPacket::Header));
    IRequest*	IR = new T(s);
    return IR;
  }

  static IRequest* unpack(TCPPacket *pack)
  {
	  auto req_elt = PackMan::request_tab.find(static_cast<eRequestType>(pack->H.type));

	  if (req_elt != PackMan::request_tab.end())
	    return req_elt->second(pack);

	  IRequest*	IR = new ACK(G_request_not_found);
	  
	  return IR;
  }
};

#endif
