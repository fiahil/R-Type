
#pragma once

#include <string>

class ISpriteSheet
{
public:
	virtual ~ISpriteSheet(void) {};
	virtual void	playAnimation(int) = 0;
	virtual void	draw() = 0;
	virtual	void	moveTo(int, int) = 0;
	virtual	void	moveFrom(int, int) = 0;
};