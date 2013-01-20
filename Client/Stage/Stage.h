#pragma once

#include <deque>
#include "GameComponent.h"
#include "Command.h"

class Stage
{
	std::deque<GameComponent *>	deck_;

public:
	Stage(void);
	~Stage(void);
	void	treatMove(Command<Move> *);
	void	treatDeath(Command<Death> *);
	void	treatShoot(Command<Fire> *);
	void	treatNewEntity(Command<NewEntity> *);
	void	update();
	void	draw();
	void add(GameComponent *);
};

