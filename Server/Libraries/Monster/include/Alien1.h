#pragma once

#include <deque>

#include "AEntityMonster.h"

class	Alien1 :	public AEntityMonster
{
public:
	Alien1(const Point& pos, const Point& dir);

public:
	virtual ~Alien1();
};
