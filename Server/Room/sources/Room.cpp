
#include "Room.h"

#include "logger.h"

/* Used to always provide a unique value to [id_] */
int Room::currentId_ = 0;

Room::Room(void)
	:	id_(currentId_++),
		isPlaying_(false),
		engine_(0),
		scenario_(0)
{
	DEBUG << "--Construction Room" << std::endl;
}


Room::~Room(void)
{
	DEBUG << "--Destruction Room" << std::endl;
}


/* Useful for ThreadPool */
void		Room::operator()(void) {}


/* Returns the IPlayer that matches the IService [s]; overwize returns 0 */
IPlayer *	Room::operator()(IService *s) const
{
	if (!s) return 0;

	for (std::deque<IPlayer *>::const_iterator it = this->players_.begin() ;
		it != this->players_.end() ; ++it)
	{
		IPlayer *tmp = *it;

		if (tmp && tmp->getService() == s)
			return tmp;
	}
	return 0;
}


/* Returns the IPlayer that matches the IPlayer* [p]; overwize returns 0 */
IPlayer *	Room::operator()(IPlayer *p) const
{
	if (!p) return 0;

	int idTest = p->getId();

	for (std::deque<IPlayer *>::const_iterator it = this->players_.begin() ;
		it != this->players_.end() ; ++it)
	{
		IPlayer *tmp = *it;

		if (tmp && tmp->getId() == idTest)
			return tmp;
	}
	return 0;
}

/* Returns the position of the IPlayer that matches the id [idTest]; overwize returns -1 */
int		Room::operator()(int idTest) const
{
	int pos = 0;

	for (std::deque<IPlayer *>::const_iterator it = this->players_.begin() ;
		it != this->players_.end() ;
		++it, ++pos)
	{
		IPlayer *tmp = *it;

		if (tmp && tmp->getId() == idTest)
			return pos;
	}
	return -1;
}

int		Room::getId() const
{
	return this->id_;
}


void	Room::addPlayer(IPlayer *p)
{
	DEBUG << "{Room::addPlayer}..." << std::endl;

	if (!p) { std::cerr << "[Error] : player NULL" << std::endl; return; }

	/* checks if any player in deque has the same id as [p] using operator() */
	IPlayer *tmp = (*this)(p);

	if (tmp)
	{
		std::cerr	<< "[Error] : A player already owns the same id [" << tmp->getId()
					<< "] as the new player" << std::endl;
		return;
	}

	/* Adding the new IPlayer [p]*/
	if (!this->isFull())
		{
			this->players_.push_back(p);
			DEBUG << "[Ok] addPlayer" << std::endl;
		}
	else { std::cerr << "[Error] : Room and new player are OK, but Room is full" << std::endl; }
}


void	Room::removePlayer(int idPlayer)
{
	DEBUG << "{Room::removePlayer}..." << std::endl;
	DEBUG << "-> Id to find player is [" << idPlayer << "]" << std::endl;

	if (this->isEmpty())
	{
		std::cerr << "[Error] : Room is empty !" << std::endl;
		return;
	}

	/* checks if any Player in deque has the same id as [idPlayer] using operator() */
	int pos = (*this)(idPlayer);

	if (pos == -1)
	{
		std::cerr	<< "[Error] : No players corresponds to the ID [" << idPlayer << "]" << std::endl;
		return;
	}

	/* Remove fetched player from deque */
	std::deque<IPlayer *>::iterator itFetchedPlayer = this->players_.begin() + pos;
	this->players_.erase(itFetchedPlayer);

	DEBUG << "[Ok] removePlayer" << std::endl;
}


IPlayer *	Room::getPlayerByService(IService *s) const
{
	return (*this)(s);
}


void		Room::setStatus(bool status)
{
	this->isPlaying_ = status;
}

bool	Room::isEmpty() const
{
	return this->players_.empty();
}


bool	Room::isFull() const
{
	return (this->players_.size() >= 4);
}


const std::deque<IPlayer *> & Room::getAllPlayers() const
{
	return this->players_;
}