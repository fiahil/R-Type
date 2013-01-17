#pragma once

#include <deque>

#include "AMonster.h"

class	Alien1 :	public AMonster
{
public:
	Alien1(const Point& pos, const Point& dir);

public:
	virtual ~Alien1();
};
