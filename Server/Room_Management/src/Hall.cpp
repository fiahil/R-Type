#include "Hall.h"

#include <iostream> // remove

Hall::Hall(void)
{
	std::cout << "--Construction Hall" << std::endl;
}

Hall::~Hall(void)
{
	std::cout << "--Destruction Hall" << std::endl;
}


/* Returns an IPlayer* if the function worked, or 0 if it failed */
IPlayer *	Hall::operator()(IPlayer *p)
{
	if (!p) return 0;

	/* checks if any player in deque has the same id as [p] */
	int idTest = p->getId();

	for (std::deque<IPlayer *>::iterator it = this->players_.begin() ;
		it != this->players_.end() ; ++it)
	{
		IPlayer *tmp = *it;
		if (tmp && tmp->getId() == idTest)
			return tmp;
	}
	/* it failed */
	return 0;
}


/* Returns the position of the IPlayer that matches the id [idTest]; overwize returns -1 */
int		Hall::operator()(int idTest)
{
	int pos = 0;

	for (std::deque<IPlayer *>::iterator it = this->players_.begin() ;
		it != this->players_.end() ;
		++it, ++pos)
	{
		IPlayer *tmp = *it;

		/* checks if any player in deque has the same id as [idTest] */
		if (tmp && tmp->getId() == idTest)
			return pos;
	}
	/* it failed */
	return -1; 
}


void	Hall::addPlayer(IPlayer *p)
{
	std::cout << "\n{Hall::addPlayer}..." << std::endl;

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
	this->players_.push_back(p);
	std::cout << "[Ok] addPlayer" << std::endl;
}

void	Hall::removePlayer(int idPlayer)
{
	std::cout << "\n{Hall::removePlayer}..." << std::endl;	
	std::cout << "-> Id to find player is [" << idPlayer << "]" << std::endl;

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

	std::cout << "[Ok] removePlayer" << std::endl;
}


IPlayer *	Hall::clonePlayer(int idPlayer)
{
	std::cout << "\n{Hall::clonePlayer}..." << std::endl;	
	std::cout << "-> Id to find player is [" << idPlayer << "]" << std::endl;

	/* checks if any Player in deque has the same id as [idPlayer] using operator() */
	int pos = (*this)(idPlayer);

	if (pos == -1)
	{
		std::cerr	<< "[Error] : No players corresponds to the ID [" << idPlayer << "]" << std::endl;
		return 0;
	}

	/* Remove fetched player from deque and returns it */
	IPlayer *ret = this->players_.at(pos);

	std::cout << "[Ok] clonePlayer" << std::endl;
	return ret;
}


// test : remove this method
void	Hall::speach()
{
	std::cout << "\n[HALL SPEACH]" << std::endl;
	for (std::deque<IPlayer *>::iterator it = this->players_.begin() ;
		it != this->players_.end() ; ++it)
	{
		IPlayer *tmp = *it;

		std::cout << "Player : id = [" << tmp->getId() << "]" << std::endl;
	}
	std::cout << "Total players : " << this->players_.size() << "\n" << std::endl;
}
