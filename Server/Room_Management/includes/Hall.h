#pragma once

#include <deque>
#include "IPlayer.h"

class Hall
{
private:
	std::deque<IPlayer *>	players_;

public:
	Hall(void);
	~Hall(void);

	IPlayer *	operator()(IPlayer *p);	/* test if player is in deque : useful for method addPlayer */
	int			operator()(int idTest);	/* test if player is in deque : useful for method removePlayer */

public:
	void		addPlayer(IPlayer *p);
	void		removePlayer(int idPlayer);
	IPlayer *	clonePlayer(int idPlayer);

	void		speach();	// remove : test
};

