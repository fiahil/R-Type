//
// PackMan.hpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Fri Jan  4 17:31:36 2013 alexandre teisseire
// Last update Fri Jan  4 17:56:31 2013 alexandre teisseire
//

#ifndef	_PACKMAN_HPP_
#define _PACKMAN_HPP_

#include <iostream> // TODO

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

  template<typename T>
  static TCPPacket*	pack(T* a, eRequestType type)
  {
    TCPPacket*	pack = new TCPPacket();
    std::string	val = a->toString();
    
    pack->H.type = type;
    PackMan::Memcpy(pack->B, val.data(), val.size());
    pack->H.size = val.size() + (2 * sizeof(int16_t));

    return (pack);
  }

  template <class T>
  static IRequest*	unpack_T(TCPPacket *pack)
  {
	  std::cout << pack->Body << std::endl;
	  std::cout << pack->H.len << std::endl;
	  //return new T(std::string(pack->Body, pack->H.len - sizeof(TCPPacket::Header))); // TODO Missing ctor.
	  return 0; // TODO Missing Ctor
  }

  static IRequest* unpack(TCPPacket *pack)
  {
	  auto req_elt = PackMan::request_tab.find(static_cast<eRequestType>(pack->H.type));

	  if (req_elt != PackMan::request_tab.end())
	    return req_elt->second(pack);
	  return 0;
  }
};

#endif
