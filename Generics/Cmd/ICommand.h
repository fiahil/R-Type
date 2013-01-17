
#pragma once

#include	"UDPPacket.h"

enum eCommandType {
	MOVE = 101,
	FIRE = 102
};

class ICommand
{
public:
	virtual eCommandType getType() const = 0;
};