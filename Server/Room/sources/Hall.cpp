#include "Hall.h"
#include "Player.h"

#include <iostream> // remove

Hall::Hall(void)
{
	std::cout << "--Construction Hall" << std::endl;
}


Hall::~Hall(void)
{
	std::cout << "--Destruction Hall" << std::endl;
}


/* Returns the position of the IPlayer that matches the id [idTest]; overwize returns -1 */
int		Hall::operator()(int idTest) const
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


/* Returns the IPlayer that matches the name and hash; overwize returns 0 */
IPlayer *	Hall::operator()(const std::string &name, const std::string &hash, bool useHash) const
{
	for (std::deque<IPlayer *>::const_iterator it = this->players_.begin() ;
		it != this->players_.end() ; ++it)
	{
		IPlayer *tmp = *it;

		if (useHash)
		{
			if (tmp && tmp->getName() == name && tmp->getHash() == hash)
				return tmp;
		}
		else
			if (tmp && tmp->getName() == name)
				return tmp;
	}
	return 0;
}


/* Returns the IPlayer that matches the Service [s]; overwize returns 0 */
IPlayer *		Hall::operator()(IService *s) const
{
	int pos = 0;

	for (std::deque<IPlayer *>::const_iterator it = this->players_.begin() ;
		it != this->players_.end() ;
		++it, ++pos)
	{
		IPlayer *tmp = *it;

		if (tmp && tmp->getService() == s)
			return tmp;
	}
	return 0; 
}


void	Hall::addPlayer(const std::string &name, const std::string &hash, IService *playerService)
{
	std::cout << "\n{Hall::addPlayer}..." << std::endl;

	if (name.empty() || hash.empty() || !playerService)
		{ std::cerr << "[Error] : Bad parameter" << std::endl; return; }

	/* checks if any player in deque has the same name_ / hash_ as [name / hash] using operator() */
	IPlayer *tmp = (*this)(name, hash, true);

	if (tmp)
	{
		std::cerr	<< "[Error] : A player already owns the same name [" << tmp->getName()
					<< "], or hash [" << tmp->getHash() << "] as the new player" << std::endl;
		return;
	}

	/* Adding IPlayer [p] to deque */
	tmp = new Player(name, hash, playerService);
	this->players_.push_back(tmp);

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


IPlayer *	Hall::clonePlayer(int idPlayer) const
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

	std::cout << "[Ok] clonePlayer" << std::endl;
	return this->players_.at(pos);
}


const std::deque<IPlayer *> &	Hall::getAllPlayers() const
{
	return this->players_;
}