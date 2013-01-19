
#pragma once

#include	<list>
#include	"ICollidable.h"

class Collider
{

public:
	Collider();
	~Collider();
	bool	collide(std::list<ICollidable *>&, ICollidable *); 
};