#pragma once

<<<<<<< HEAD
#include <cstdint>
=======
#include <string>

struct	Point
{
	int	x_;
	int	y_;

	Point(int x, int y)
		:	x_(x), y_(y) {}

	Point(const Point& other)
		:	x_(other.x_), y_(other.y_) {}
};

enum	eSkin
{
/* Lvl 1*/
	Alien_1,		// small red
	Alien_2,		// small glod
	Alien_3,		// green
	Alien_4,		// steel
	Alien_5,		// orange 
	Apu_1,			// orange
	Apu_2,			// blue
	Ball_1,			// white
	Disc_1,			// grey-orange
	Disc_2,			// blue-orange
	Turret_1,		// small white-orange
	BossLvl_1,		// Boss lvl 1
/* Others */
	ErrorSkin
};
>>>>>>> 5b1a32f69af3e5002c88100c2e0c19e44b8da9ea

class	IEntity
{
public:
	virtual ~IEntity() {}

public:
	virtual uint16_t	getId() const	= 0;
};