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
	bool					isPlaying_;
	std::deque<IPlayer *>	players_;
	GameplayEngine *		engine_;
	Scenario *				scenario_;

/* Used to always provide a unique value to [id_] */
private:
	static int	currentId_;

public:
	Room(void);
	virtual ~Room(void);

	IPlayer *	operator()(IService *s) const;		/* Useful for method getPlayerByService  */
	IPlayer *	operator()(IPlayer *p) const;		/* Useful for method addPlayer */
	int			operator()(int idTest) const;		/* Useful for method removePlayer */

/* Methods herited from IRoom */
public:
	virtual int			getId() const;
	virtual void		addPlayer(IPlayer *p);
	virtual void		removePlayer(int idPlayer);
	virtual IPlayer *	getPlayerByService(IService *s) const;
	virtual	void		setStatus(bool status); 
	virtual bool		isEmpty() const;
	virtual bool		isFull() const;
	virtual const std::deque<IPlayer *> & getAllPlayers() const;
};

