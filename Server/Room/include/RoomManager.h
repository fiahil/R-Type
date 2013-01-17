#pragma once

#include <deque>
#include "IRoom.h"
#include "IPlayer.h"
#include "Hall.h"
#include "ThreadPool.h"

class RoomManager
{
private:
	std::deque<IRoom *>			rooms_;
	Hall *						hall_;
	unsigned int				nbMaxGames_;
	TP::ThreadPool<IRoom> *		tp_;

public:
	RoomManager(void);
	~RoomManager(void);


	int			operator()(int idTest) const;				/* Useful for method removeRoom, getRoomById */
	IPlayer *	operator()(IService * playerService) const;	/* Useful for IService management */

public:
	/* General */
	bool	isFull();
	void	setNbGames(int nbr);
	void	linkRoomToThreadPool(int idRoom);

	/* Room dealing methods */
	int		createRoom();
	void	removeRoom(int idRoom);
	void	removePlayerFromRoom(int idPlayer, int idRoom);
	void	clonePlayerFromHallToRoom(int idRoom, int idPlayer);

	/* Hall dealing methods */
	void	addPlayerToHall(const std::string &name, const std::string &hash, IService *playerService);
	void	removePlayerFromHall(int idPlayer);

	/* IServices dealing methods */
	IPlayer *	getPlayerFromName(std::string & name) const;
	IPlayer	*	getPlayerFromService(IService * name) const;
	IPlayer *	getPlayerFromHall(IService * playerService) const;
	IPlayer *	getPlayerFromRoom(IService * playerService, int roomId) const;
	IRoom *		getRoomById(int idRoom) const;
	void		setRoomStatus(int idRoom, bool status);
	const std::deque<IPlayer *> &	getPlayersFromRoom(int roomId) const;
};

