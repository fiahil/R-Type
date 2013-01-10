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

	int			operator()(int idTest) const;		/* Useful for method removePlayer */
	IPlayer *	operator()(IService *s) const;		/* Useful for RoomManager */
	IPlayer *	operator()(const std::string &name, const std::string &hash, bool useHash) const;	/* Useful for method addPlayer */

public:
	void		addPlayer(const std::string &name, const std::string &hash, IService *playerService);
	void		removePlayer(int idPlayer);
	IPlayer *	clonePlayer(int idPlayer) const;
	const std::deque<IPlayer *> &	getAllPlayers() const;
};

