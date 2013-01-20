#include "GameplayEngine.h"
#include <string>
#include "logger.h"

GameplayEngine::GameplayEngine(void) : quad_(0)
{
	DEBUG << "--Construction GameplayEngine" << std::endl;
}

GameplayEngine::~GameplayEngine(void)
{
	if (quad_)
		delete quad_;
	for (std::list<IEntity *>::iterator it = list_.begin(); it != list_.end();)
		list_.erase(it);

	DEBUG << "--Destruction GameplayEngine" << std::endl;
}

void	GameplayEngine::createQuadTree(int x, int y, unsigned int maxEPN, unsigned int maxDepth)
{
	if (quad_)
	{
		delete quad_;
		quad_ = 0;
	}

	quad_ = new QuadTree(x, y, maxEPN, maxDepth);
}


void	GameplayEngine::addEntity(IEntity *entity)
{
	list_.push_back(entity);

	/*
	if (dynamic_cast<IPlayable>(*entity))
		quad_->addShip(entity);

	else if (dynamic_cast<IBullet>(*entity))
		quad_->addBullet(entity);

	else
		quad_->addEnemy(entity);
	*/
}

void	GameplayEngine::removeEntity(IEntity *entity)
{
	std::list<IEntity *>::iterator it = list_.begin();

	for (; it != list_.end(); ++it)
	{
		if ((*it) == entity)
		{
			list_.erase(it);
			break;
		}
	}
}
