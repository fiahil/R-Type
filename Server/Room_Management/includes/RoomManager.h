#pragma once

#include <deque>
#include "IRoom.h"
#include "IPlayer.h"
#include "Hall.h"

class RoomManager
{
private:
	std::deque<IRoom *>	rooms_;
	Hall				hall_;	// pointer ? (memory low-cost)
	unsigned int				nbMaxGames;

public:
	RoomManager(void);
	~RoomManager(void);

	/* test if Room is in deque : useful for method removeRoom */
	int	operator()(int idTest);

public:
	/* General */
	bool	isFull();
	void	setNbGames(int nbr);

	/* Room dealing methods */
	int		createRoom();
	void	removeRoom(int idRoom);
	void	removePlayerFromRoom(int idRoom, int idPlayer);
	void	clonePlayerFromHallToRoom(int idRoom, int idPlayer);

	/* Hall dealing methods */
	void	addPlayerToHall(IPlayer *p);
	void	removePlayerFromHall(int idPlayer);

	void	hallSpeach();	// test : remove this method
	void	roomSpeach();	// test : remove this method
};

