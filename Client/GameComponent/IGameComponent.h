

#pragma once

#include "ISpriteSheet.h"

enum eStatus {
IDLE,
MOVE,
SHOOT,
DEATH
};


class IGameComponent
{
public:
	virtual ~IGameComponent() {};
	virtual	void	draw() = 0;
	virtual void	initialize(ISpriteSheet *, ISpriteSheet*) = 0;
	virtual void	release() = 0;
	virtual void	update() = 0;
	virtual	void	move(int, int) = 0;
	virtual	void	death() = 0;
};

