
#pragma once

#include	"UDPPacket.h"

struct CommandType
{
	enum eCommandType
	{
		MOVE = 101,
		FIRE = 102,
		DEATH = 103,
		NEW_ENT = 104,
		INPUT = 201
	};
};

class ICommand
{
public:
	virtual CommandType::eCommandType getType() const = 0;
};
