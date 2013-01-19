
#include	"Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

ICollidable*	Collider::collide(std::list<ICollidable *>& items, ICollidable *object)
{
	std::list<ICollidable *>::iterator it = items.begin();
	HitBox	hit;
	const	HitBox	box = object->getHitBox();

	for (; it != items.end(); ++it)
	{
		hit = (*it)->getHitBox();

		if (hit.xmin_ < box.xmin_ &&  hit.xmin_ > box.xmax_ &&
			hit.ymin_ > box.ymin_ &&  hit.ymin_ < box.ymax_)
				return (*it);
		if (hit.xmin_ < box.xmin_ &&  hit.xmin_ > box.xmax_ &&
			hit.ymax_ > box.ymin_ &&  hit.ymax_ < box.ymax_)
				return (*it);
		if (hit.xmax_ < box.xmin_ &&  hit.xmax_ > box.xmax_ &&
			hit.ymin_ > box.ymin_ &&  hit.ymin_ < box.ymax_)
				return (*it);
		if (hit.xmax_ < box.xmin_ &&  hit.xmax_ > box.xmax_ &&
			hit.ymax_ > box.ymin_ &&  hit.ymax_ < box.ymax_)
				return (*it);
		if (box.xmin_ < hit.xmin_ &&  box.xmin_ > hit.xmax_ &&
			box.ymin_ > hit.ymin_ &&  box.ymin_ < hit.ymax_)
				return (*it);
		if (box.xmin_ < hit.xmin_ &&  box.xmin_ > hit.xmax_ &&
			box.ymax_ > hit.ymin_ &&  box.ymax_ < hit.ymax_)
				return (*it);
		if (box.xmax_ < hit.xmin_ &&  box.xmax_ > hit.xmax_ &&
			box.ymin_ > hit.ymin_ &&  box.ymin_ < hit.ymax_)
				return (*it);
		if (box.xmax_ < hit.xmin_ &&  box.xmax_ > hit.xmax_ &&
			box.ymax_ > hit.ymin_ &&  box.ymax_ < hit.ymax_)
				return (*it);
	}
	return 0;
}