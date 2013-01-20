#include "GameplayEngine.h"
#include "logger.h"
#include "Cmd.h"
#include "PackMan.h"
#include "IClientService.h"
#include "Command.h"


Dl::DlManager<PackedPlugin> * GameplayEngine::manager_ = 0;

GameplayEngine::GameplayEngine(std::string path, std::deque<IPlayer*>& players): players_(players) {
  this->coll_ = new Collider();
  this->quad_ = new QuadTree(800, 600, 5, 5);
  this->manager_ = new Dl::DlManager<PackedPlugin>();
  this->manager_->loadPlugin(path);

  if (this->manager_->isPluginLoaded("Stage_1") == true) {
    PackedPlugin * pp_ = this->manager_->getObject("Stage_1");
	this->gm_ = pp_->gm_;
	this->sc_ = pp_->sc_;
	DEBUG << "Success on the recuperation of the pack : " << path << std::endl;
  }
  else
    DEBUG << "Error on the pack selected : " << path << std::endl;
}

GameplayEngine::~GameplayEngine() {
  delete this->coll_;
  delete this->quad_;
}

void GameplayEngine::handleEvent(/*Event & evt*/) {
  // A coder une fois que la class Event est prete
}

void GameplayEngine::plugEntity(ICollidable * E) {

}

template<typename T, typename U>
U *	cast_entity(T * m)
{
	return (dynamic_cast<U *>(m));
}

void	GameplayEngine::refreshEntitiesPositions()
{
	for (std::deque<IEntity *>::iterator it = this->entities_.begin() ;
		it != this->entities_.end() ; ++it)
	{
		IEntity *		fetch = *it;
		IMoveable *		m = 0;
		
		if ((m = cast_entity<IEntity, IMoveable>(fetch)))
		{
			Point pos = m->getPosition();

			m->setPosition(pos.x_ - 20, pos.y_);
		}
	}
}

void GameplayEngine::update()
{
	this->refreshEntitiesPositions();

	this->quad_->update(this->gm_);
}

bool	GameplayEngine::isGameEnded() const
{
	bool	res = false;

	for (unsigned int i = 0; i < players_.size(); ++i)
	{
		res |= players_.at(i)->isPlaying();
	}

	return res;
}

bool	GameplayEngine::isPlayerDead(int nb) const
{
	return players_.at(nb)->isPlaying();
}

void	GameplayEngine::treatPlayersCommands(std::queue<ICommand *>	& cmds)
{
	for (std::deque<IPlayer *>::iterator it = this->players_.begin() ;
				it != this->players_.end() ; ++it)
		{
			IPlayer *fetch = *it;

			ICommand *tmp = dynamic_cast<IClientService *>(fetch->getService())->Zpull();

			if (tmp && tmp->getType() == CommandType::MOVE)
			{
			}
			/* ... */
		}
}
