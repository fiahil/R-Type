#pragma once

#include "IGameComponent.h"
#include "sfSpriteSheet.h"

class GameComponent :
	public IGameComponent
{
	ISpriteSheet*	sprite_;
	ISpriteSheet*	death_;
	eStatus			state_;
	int				x_;
	int				y_;
	bool			endLife_;

public:
	GameComponent(ISpriteSheet* s, ISpriteSheet* d);
	~GameComponent(void);
	void	draw();
	void	initialize(ISpriteSheet *, ISpriteSheet*);
	void	release();
	void	update();
	void	move(int, int);
	void	death();
	bool	getEndLife() const;
};
