#pragma once

#include <deque>
#include "IRoom.h"
#include "IPlayer.h"
#include "GameplayEngine.h"
#include "Scenario.h"

class Room : public IRoom
{
private:
	int						id_;
	std::deque<IPlayer *>	players_;
	GameplayEngine *			engine_;
	Scenario *				scenario_;

/* Used to always provide a unique value to [id_] */
private:
	static int	currentId_;

public:
	Room(void);
	virtual ~Room(void);

	IPlayer *	operator()(IPlayer *p);	/* test if player is in deque : useful for method addPlayer */
	int			operator()(int idTest);	/* test if player is in deque : useful for method removePlayer */

/* Methods herited from IRoom */
public:
	virtual int			getId() const;
	virtual void		addPlayer(IPlayer *p);
	virtual void		removePlayer(int idPlayer);
	virtual bool		isEmpty() const;
	virtual bool		isFull() const;
};

