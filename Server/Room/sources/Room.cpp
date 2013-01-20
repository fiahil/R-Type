
#include <queue>
#include "Room.h"
#include "logger.h"
#include "Command.h"
#include "IClock.h"
#include "Cmd.h"
#include "PackMan.h"
#include "IClientService.h"

/* Used to always provide a unique value to [id_] */
int Room::currentId_ = 0;

#ifdef	WIN32
	#include "WinGameClock.h"
#else
	#include "UnixGameClock.h"
#endif


Room::Room(void)
	:	id_(currentId_++),
		isPlaying_(false),
		engine_(0)
{
	DEBUG << "--Construction Room" << std::endl;
}


Room::~Room(void)
{
	DEBUG << "--Destruction Room" << std::endl;
}


void		Room::loadGame()
{
	DEBUG << "Loading Game" << std::endl;

	this->engine_ = new GameplayEngine("Stage_1.dll", this->players_);
}


template<typename T, typename U>
U *	cast_entity(T * m)
{
	return (dynamic_cast<U *>(m));
}

void		Room::playGame()
{
	IClock *	clock = new GameClock();
	std::queue<ICommand *>	cmds;

	DEBUG << "Playing Game" << std::endl;
	while (!this->engine_->isGameEnded())
	{
		DEBUG << "-> Loop playGame" << std::endl;
		
		IEntity	*	fetch = 0;

		/*update scenario*/
		while ((fetch = this->engine_->sc_->getNextEvent(clock->getElapsedTime())))
		{
			NewEntity ne;

			ne.id = fetch->getId();
			PackMan::Memcpy(ne.filename, "ennemy1", 7); // path
			ne.anim = 8;
			ne.frame = 1;
	
			ICollidable * c = 0;

			if ((c = cast_entity<IEntity, ICollidable>(fetch)))
				c->fetchLeftBorder(ne.x_start, ne.y_start);
			else
			{
				ne.x_start = 800;
				ne.y_start = 600;
			}

			ICommand * ic = new Command<NewEntity>(ne, CommandType::NEW_ENT);
			cmds.push(ic);
		}

		/* treat cmds */
		this->engine_->treatPlayersCommands(cmds);

		/* update engine */
		this->engine_->update();

		/* remove cmds from the queue and dispatchts it to each client */
		while (!cmds.empty())
		{
			DEBUG << "--> Loop Vidage cmds" << std::endl;
		
			ICommand * tmp = cmds.front();

			for (std::deque<IPlayer *>::iterator it = this->players_.begin() ;
				it != this->players_.end() ; ++it)
			{
				IPlayer * fetch = *it;

				dynamic_cast<IClientService *>(fetch->getService())->push(tmp);
			}

			cmds.pop();
		}

	}
	delete clock;
}


/* Useful for ThreadPool : used to launch the game */
void		Room::operator()(void)
{
	this->loadGame();
	this->playGame();
}


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