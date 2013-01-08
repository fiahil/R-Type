
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

		if ((*it)->getXUp() < object->getXUp() &&  (*it)->getXUp() > object->getXDown() &&
			(*it)->getYLeft() > object->getYLeft() &&  (*it)->getYLeft() < object->getYRight())
				hasCollide = true;
		if ((*it)->getXUp() < object->getXUp() &&  (*it)->getXUp() > object->getXDown() &&
			(*it)->getYRight() > object->getYLeft() &&  (*it)->getYRight() < object->getYRight())
				hasCollide = true;
		if ((*it)->getXDown() < object->getXUp() &&  (*it)->getXDown() > object->getXDown() &&
			(*it)->getYLeft() > object->getYLeft() &&  (*it)->getYLeft() < object->getYRight())
				hasCollide = true;
		if ((*it)->getXDown() < object->getXUp() &&  (*it)->getXDown() > object->getXDown() &&
			(*it)->getYRight() > object->getYLeft() &&  (*it)->getYRight() < object->getYRight())
				hasCollide = true;
	}
	return hasCollide;
}