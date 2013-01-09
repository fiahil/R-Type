#include <algorithm>
#include "RoomManager.h"
#include "Room.h"

#include <iostream> // remove

RoomManager::RoomManager(void)
	: nbMaxGames(4)
{
	std::cout << "--Construction RoomManager" << std::endl;
}


RoomManager::~RoomManager(void)
{
	std::cout << "--Destruction RoomManager" << std::endl;
}


/* Returns the position of the IRoom that matches the id [idTest]; overwize returns -1 */
int		RoomManager::operator()(int idTest)
{
	int pos = 0;

	for (std::deque<IRoom *>::iterator it = this->rooms_.begin() ;
		it != this->rooms_.end() ;
		++it, ++pos)
	{
		IRoom *tmp = *it;

		/* Checks if any IRoom in deque has the same id as [idTest] */
		if (tmp && tmp->getId() == idTest)
			return pos;
	}
	return -1;
}


bool		RoomManager::isFull()
{
	return (this->rooms_.size() >= this->nbMaxGames);
}


void		RoomManager::setNbGames(int nbr)
{
	std::cout << "\n{RoomManager::setNbGames}..." << std::endl;
	if (nbr > 0)
	{
		std::cout << "[Ok] setNbGames : [" << nbr << "]" << std::endl;
		this->nbMaxGames = nbr;
	}
	else
		std::cerr << "[Error] : Bad Nbr" << std::endl;
}


int		RoomManager::createRoom()
{
	std::cout << "\n{RoomManager::createRoom}..." << std::endl;

	if (!this->isFull())
	{
		IRoom * toAdd = new Room();

		std::cout << "[Ok] createRoom" << std::endl;
		this->rooms_.push_back(toAdd);

		return toAdd->getId();
	}
	std::cerr << "[Error] : Room Manager is FULL of rooms" << std::endl;
	return -1;
}


void	RoomManager::removeRoom(int idRoom)
{
	std::cout << "\n{RoomManager::removeRoom}..." << std::endl;
	std::cout << "id to remove is [" << idRoom << "]" << std::endl;

	/* checks if any Room in [rooms_]'s deque has the same id as [idRoom] using operator() */
	int pos = (*this)(idRoom);

	if (pos == -1)
	{
		std::cerr << "[Error] : No Room corresponds to ID ["  << idRoom << "]" << std::endl;
		return;
	}
	
	/* Remove fetched room from [rooms_]'s deque */
	std::deque<IRoom *>::iterator itFetchedRoom = this->rooms_.begin() + pos;
	this->rooms_.erase(itFetchedRoom);

	std::cout << "[Ok] removeRoom" << std::endl;
}


void	RoomManager::removePlayerFromRoom(int idRoom, int idPlayer)
{
	std::cout << "\n{RoomManager::removePlayerFromRoom}..." << std::endl;

	std::cout << "Player's id [" << idPlayer << "]" << std::endl;
	std::cout << "Room's id [" << idRoom << "]" << std::endl;

	/* checks if any Room in [rooms_]'s deque has the same id as [idRoom] using operator() */
	int pos = (*this)(idRoom);
	
	if (pos == -1)
	{
		std::cerr << "[Error] : No Room corresponds to ID ["  << idRoom << "]" << std::endl;
		return;
	}

	/* Room & Player OK, removing player from fetched room */
	IRoom *	fetchedRoom = this->rooms_.at(pos);
	if (!fetchedRoom)
	{
		std::cerr << "[Error] : Akward error occured on fetching room" << std::endl;
		return;
	}

	fetchedRoom->removePlayer(idPlayer);
	std::cout << "[Ok] removePlayerFromRoom" << std::endl;
}


void	RoomManager::clonePlayerFromHallToRoom(int idRoom, int idPlayer)
{
	std::cout << "\n{RoomManager::clonePlayerFromHallToRoom}..." << std::endl;

	/* Clones a IPlayer from Hall */
	IPlayer * clone = this->hall_.clonePlayer(idPlayer);
	if (!clone) { std::cerr << "[Error] : Cloned IPlayer is NULL" << std::endl; return ; }


	/* Checks if any IRoom in [rooms_]'s deque has the same id as [idRoom] using operator() */
	int pos = (*this)(idRoom);
	if (pos == -1)
	{
		std::cerr << "[Error] : No Room corresponds to ID ["  << idRoom << "]" << std::endl;
		return;
	}

	/* IRoom & IPlayer OK, adding player to fetched room */
	IRoom *fetchedRoom = this->rooms_.at(pos);
	fetchedRoom->addPlayer(clone);
	std::cout << "[Ok] clonePlayerFromHallToRoom" << std::endl;
}


void	RoomManager::addPlayerToHall(IPlayer *p)
{
	this->hall_.addPlayer(p);
}


void	RoomManager::removePlayerFromHall(int idPlayer)
{
	this->hall_.removePlayer(idPlayer);
}


// test method : remove it
void		RoomManager::roomSpeach()
{
	std::cout << "\n[ROOM SPEACH]" << std::endl;
	for (std::deque<IRoom *>::iterator it = this->rooms_.begin() ;
		it != this->rooms_.end() ; ++it)
	{
		IRoom *tmp = *it;

		std::cout << "Room : id = [" << tmp->getId() << "]" << std::endl;
	}
	std::cout << "Total rooms : " << this->rooms_.size() << "\n" << std::endl;
}


// test method : remove it
void		RoomManager::hallSpeach()
{
	this->hall_.speach();
}
