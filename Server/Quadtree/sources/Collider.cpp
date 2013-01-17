
#include	"Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

bool	Collider::collide(std::list<IEntity *>& items, IEntity *object)
{
	bool	hasCollide = false;
	std::list<IEntity *>::iterator it = items.begin();

	for (; it != items.end(); ++it)
	{
		/*
		if ((*it)->getXUp() < object->getXUp() &&  (*it)->getXUp() > object->getXDown() &&
			(*it)->getYLeft() > object->getYLeft() &&  (*it)->getYLeft() < object->getYRight())
				{
					hasCollide = true;
					continue ;
				}
		if ((*it)->getXUp() < object->getXUp() &&  (*it)->getXUp() > object->getXDown() &&
			(*it)->getYRight() > object->getYLeft() &&  (*it)->getYRight() < object->getYRight())
				{
					hasCollide = true;
					continue ;
				}
		if ((*it)->getXDown() < object->getXUp() &&  (*it)->getXDown() > object->getXDown() &&
			(*it)->getYLeft() > object->getYLeft() &&  (*it)->getYLeft() < object->getYRight())
				{
					hasCollide = true;
					continue ;
				}
		if ((*it)->getXDown() < object->getXUp() &&  (*it)->getXDown() > object->getXDown() &&
			(*it)->getYRight() > object->getYLeft() &&  (*it)->getYRight() < object->getYRight())
				{
					hasCollide = true;
					continue ;
				}

		if (object->getXUp() < (*it)->getXUp() &&  object->getXUp() > (*it)->getXDown() &&
			object->getYLeft() > (*it)->getYLeft() &&  object->getYLeft() < (*it)->getYRight())
				{
					hasCollide = true;
					continue ;
				}
		if (object->getXUp() < (*it)->getXUp() &&  object->getXUp() > (*it)->getXDown() &&
			object->getYRight() > (*it)->getYLeft() &&  object->getYRight() < (*it)->getYRight())
				{
					hasCollide = true;
					continue ;
				}
		if (object->getXDown() < (*it)->getXUp() &&  object->getXDown() > (*it)->getXDown() &&
			object->getYLeft() > (*it)->getYLeft() &&  object->getYLeft() < (*it)->getYRight())
				{
					hasCollide = true;
					continue ;
				}
		if (object->getXDown() < (*it)->getXUp() &&  object->getXDown() > (*it)->getXDown() &&
			object->getYRight() > (*it)->getYLeft() &&  object->getYRight() < (*it)->getYRight())
				{
					hasCollide = true;
					continue ;
				}
				*/
	}
	return hasCollide;
}