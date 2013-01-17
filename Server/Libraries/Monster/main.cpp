
#include <iostream>
#include <deque>

#include "IEntity.h"
#include "IDrawable.h"
#include "IArmable.h"
#include "ICollidable.h"
#include "IMoveable.h"
#include "IDestroyable.h"
#include "IScriptable.h"
#include "IPlayable.h"
#include "Alien1.h"

template<typename T, typename U>
U*	test_cast(T* m)
{
	return (dynamic_cast<U *>(m));
}

void	test_IEntity(IEntity * E)
{
	int		x = -1;
	int		y = -1;

	IEntity *tmp;

	if ((tmp = test_cast<IEntity, IEntity>(E)))
	{
		tmp->fetchLeftBorder(x, y);
		std::cout	<< "Entity is an IENTITY      - has leftborder : x = " << x 
					<< ", y = "	<< y << std::endl;
	}
}

void	test_IDrawable(IEntity * E)
{
	IDrawable *tmp;

	if ((tmp = test_cast<IEntity, IDrawable>(E)))
		std::cout << "Entity is an IDRAWABLE    - has skin : " << tmp->getSkin() << std::endl;
}

void	test_IArmable(IEntity * E)
{
	IArmable *tmp;

	if ((tmp = test_cast<IEntity, IArmable>(E)))
		std::cout << "Entity is an IARMABLE     - has power : " << tmp->getPower() << std::endl;
}

void	test_ICollidable(IEntity * E)
{
	ICollidable *tmp;

	if ((tmp = test_cast<IEntity, ICollidable>(E)))
		std::cout << "Entity is an ICOLLIDABLE  - has hitbox : "
		<< "x1 = " << tmp->getHitBox().xmin_
		<< ", y1 = " << tmp->getHitBox().ymin_
		<< ", x2 = " << tmp->getHitBox().xmax_
		<< ", y2 = " << tmp->getHitBox().ymax_
		<< std::endl;
}

void	test_IMoveable(IEntity * E)
{
	IMoveable *tmp;

	if ((tmp = test_cast<IEntity, IMoveable>(E)))
	{
		std::cout << "Entity is an IMOVEABLE    - has speed : " << tmp->getSpeed();
		std::cout << ". It has direction : "
			<< "x = " << tmp->getDirection().x_
			<< ", y = " << tmp->getDirection().y_
			<< std::endl;
	}
}

void	test_IDestroyable(IEntity * E)
{
	int				nbLost = 10;
	IDestroyable *	tmp;

	if ((tmp = test_cast<IEntity, IDestroyable>(E)))
	{
		std::cout << "Entity is an IDESTROYABLE - has " << tmp->getLife();

		tmp->subLife(nbLost);
		std::cout	<< " Lives. It has lost " << nbLost
					<< " lives, has now " << tmp->getLife() << std::endl;
	}
}

void	test_IPlayable(IEntity * E)
{
	IPlayable *tmp;

	if ((tmp = test_cast<IEntity, IPlayable>(E)))
		std::cout << "Entity is an IPLAYABLE - has input " << tmp->getInput() << std::endl;
}

void	test_IScriptable(IEntity * E)
{
	IScriptable *tmp;

	if ((tmp = test_cast<IEntity, IScriptable>(E)))
	  std::cout << "Entity is an ISCRIPTABLE" << std::endl;
}

void	test_the_entity(IEntity * E)
{
	test_IEntity(E);
	test_IDrawable(E);
	test_IArmable(E);
	test_ICollidable(E);
	test_IMoveable(E);
	test_IDestroyable(E);
	test_IScriptable(E);
}

int		main()
{
	std::cout << "-- Begin --" << std::endl;

	Point	pos(50, 50);
	Point	dir(10, 10);
	HitBox	hb(50, 50, 100, 200);

	IEntity* m1 = new Alien1(pos, dir);
	test_the_entity(m1);

	for (;;);
	return 0;
}
