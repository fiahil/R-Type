
#pragma once
#include	<cstdint>

struct		TCPPacket
{
  struct	Header
  {
    int16_t	size;
    int16_t	type;
  };
  
  Header	H;
  char		B[4096];
};
