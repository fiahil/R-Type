
#pragma once

#include	"UDPPacket.h"

enum eCommandType {
	MOVE = 101,
	FIRE = 102,
	DEATH = 103,
	NEW_ENT = 104,
	INPUT = 201
};

class ICommand
{
public:
	virtual eCommandType getType() const = 0;
};
