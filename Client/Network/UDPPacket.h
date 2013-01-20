
#pragma once

#include <cstdint>

struct UDPPacket
{
	struct Header
	{
		int16_t	size;
		int16_t player;
		int32_t	type;
	};

	Header H;
	int32_t	clock;
	char value[4096];
};
