#pragma once

#include "IPlayer.h"

class IRoom
{
public:
	virtual ~IRoom(void) {}

public:
	virtual int			getId() const				= 0;
	virtual void		addPlayer(IPlayer *p)		= 0;
	virtual void		removePlayer(int idPlayer)	= 0;
	virtual bool		isEmpty() const				= 0;
	virtual bool		isFull() const				= 0;
};
