
#pragma once

#include	<list>
#include	"IEntity.h"

class Collider
{

public:
	Collider();
	~Collider();
	bool	collide(std::list<IEntity *>&, IEntity *); 
};