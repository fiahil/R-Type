//
// NetPacket.hpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan  2 11:30:41 2013 alexandre teisseire
// Last update Fri Jan  4 17:22:27 2013 alexandre teisseire
//

#pragma once

#include	<stdint.h>

struct		TCPPacket
{
  struct	Header
  {
    int16_t	len;
    int16_t	type;
  };
  
  Header	H;
  char		Body[4096];
};
