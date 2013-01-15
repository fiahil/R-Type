#include "RoomManager.h"
#include "Room.h"
#include "Hall.h"
#include "deleteObj.h"

#include <iostream> // remove

RoomManager::RoomManager(void)
	:	hall_(0),
		nbMaxGames_(10),
		tp_(0)
{
	this->hall_ = new Hall();
	this->tp_ = TP::ThreadPool<IRoom>::getInstance(this->nbMaxGames_);
	std::cout << "--Construction RoomManager" << std::endl;
}


RoomManager::~RoomManager(void)
{
	deleteObject<Hall>(this->hall_);
	// unlink toutes les room
	// faire quelque chose avec la thread pool ?
	std::cout << "--Destruction RoomManager" << std::endl;
}


/* Returns the position of the IRoom that matches the id [idTest]; overwize returns -1 */
int		RoomManager::operator()(int idTest) const
{
	int pos = 0;

	for (std::deque<IRoom *>::const_iterator it = this->rooms_.begin() ;
		it != this->rooms_.end() ;
		++it, ++pos)
	{
		IRoom *tmp = *it;

		if (tmp && tmp->getId() == idTest)
			return pos;
	}
	return -1;
}

/* Returns the IPlayer that matches the IService [s]; overwize returns 0 */
IPlayer *		RoomManager::operator()(IService * s) const
{

	std::deque<IPlayer *> players = this->hall_->getAllPlayers();

	for (std::deque<IPlayer *>::const_iterator it = players.begin() ;
		it != players.end() ; ++it)
	{
		IPlayer *tmp = *it;

		if (tmp && tmp->getService() == s)
			return tmp;
	}
	return 0;
}


bool		RoomManager::isFull()
{
	return (this->rooms_.size() >= this->nbMaxGames_);
}


void		RoomManager::setNbGames(int nbr)
{
	std::cout << "\n{RoomManager::setNbGames}..." << std::endl;
	if (nbr > 0)
	{
		std::cout << "[Ok] setNbGames : [" << nbr << "]" << std::endl;
		this->nbMaxGames_ = nbr;
	}
	else
		std::cerr << "[Error] : Bad Nbr" << std::endl;
}


void		RoomManager::linkRoomToThreadPool(int idRoom)
{
	std::cout << "\n{RoomManager::linkRoomToThreadPool}..." << std::endl;
	std::cout << "Id to find = [" << idRoom << "]" << std::endl;

	IRoom *fetch = this->getRoomById(idRoom);

	if (!fetch)
		{
			std::cerr << "[Error] : IRoom NULL" << std::endl;
			return ;
		}
	if (this->tp_->isSaturated())
		this->tp_->allocate();

	this->tp_->push(fetch);
	std::cout << "[Ok] linkRoomToThreadPool" << std::endl;
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
	IPlayer * clone = this->hall_->clonePlayer(idPlayer);
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


void	RoomManager::addPlayerToHall(const std::string &name, const std::string &hash, IService *playerService)
{
	this->hall_->addPlayer(name, hash, playerService);
}


void	RoomManager::removePlayerFromHall(int idPlayer)
{
	this->hall_->removePlayer(idPlayer);
}


IPlayer *	RoomManager::getPlayerFromName(std::string & name) const
{
	std::string empty;

	return (*this->hall_)(name, empty, false);
}


IPlayer *	RoomManager::getPlayerFromHall(IService * playerService) const
{
	return (*this->hall_)(playerService);
}


IPlayer *	RoomManager::getPlayerFromRoom(IService * playerService, int roomId) const
{
	int roomPos = (*this)(roomId);

	if (roomPos >= 0)
	{
		IRoom * tmp = this->rooms_.at(roomPos);

		if (tmp)
			return tmp->getPlayerByService(playerService);
	}
	return 0;
}


IRoom *		RoomManager::getRoomById(int idRoom) const
{
	int roomPos = (*this)(idRoom);

	if (roomPos >= 0)
		return this->rooms_.at(roomPos);
	return 0;
}


void		RoomManager::setRoomStatus(int idRoom, bool status)
{
	int roomPos = (*this)(idRoom);

	if (roomPos > 0)
	{
		IRoom * tmp = this->rooms_.at(roomPos);

		if (tmp)
			tmp->setStatus(status);
	}
}


const std::deque<IPlayer *> &	RoomManager::getPlayersFromRoom(int roomId) const
{
	// verification room pos : thow if <= 0, car on renvoie une deque

	int roomPos = (*this)(roomId);
	IRoom * tmp = this->rooms_.at(roomPos);

	// verification tmp : thow if == 0, car on renvoie une deque
	return tmp->getAllPlayers();
}