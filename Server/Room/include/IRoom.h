
#pragma once

#include <deque>
#include "IPlayer.h"
#include "IService.h"

class IRoom
{
public:
	virtual ~IRoom(void) {}
	virtual void operator()(void) = 0;	/* Useful for ThreadPool */

public:
	virtual int			getId() const							= 0;
	virtual void		addPlayer(IPlayer *p)					= 0;
	virtual void		removePlayer(int idPlayer)				= 0;
	virtual IPlayer *	getPlayerByService(IService *s)	const	= 0;
	virtual	void		setStatus(bool status)					= 0; 
	virtual bool		isEmpty() const							= 0;
	virtual bool		isFull() const							= 0;
	virtual const std::deque<IPlayer *> & getAllPlayers() const	= 0;
};
