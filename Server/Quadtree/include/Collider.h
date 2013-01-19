
#pragma once

#include	<list>
#include	"ICollidable.h"

class Collider
{

public:
	Collider();
	~Collider();
	ICollidable*	collide(std::list<ICollidable *>&, ICollidable *); 
};