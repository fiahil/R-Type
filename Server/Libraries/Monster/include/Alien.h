#include "Alien1.h"

#include <iostream> //remove

Alien1::Alien1(int life, int power, eSkin skin, float speed,
				const Point& pos, const Point& dir, const HitBox& hb)
		: AMonster(life, power, skin, speed, pos, dir, hb)
{
	// Build script here
	std::cout << "-- Construction Alien1" << std::endl;
}

Alien1::~Alien1()
{
	std::cout << "-- Destruction Alien1" << std::endl;
}