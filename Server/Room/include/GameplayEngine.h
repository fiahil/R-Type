#pragma once

#include	"QuadTree.h"

// TO DO : build this class
class GameplayEngine
{
	QuadTree				*quad_;
	std::list<IEntity *>	list_;

public:
	GameplayEngine(void);
	~GameplayEngine(void);

	void	createQuadTree(int x, int y, unsigned int maxEPN, unsigned int maxDepth);
	void	addEntity(IEntity *entity);
	void	removeEntity(IEntity *entity);
};

