
#include <iostream>

#include "IEntity.h"
#include "IDrawable.h"
#include "IArmable.h"
#include "ICollidable.h"
#include "IMoveable.h"
#include "IDestroyable.h"
#include "IScriptable.h"
#include "IPlayable.h"
#include "AEntityMonster.h"
#include "EntityDecor.h"
#include "EntityPlayer.h"
#include "EntityWeapon.h"
#include "Alien1.h"

template<typename T, typename U>
	U*	cast_entity(T* m)
{
	return (dynamic_cast<U *>(m));
}

void	test_IEntity(IEntity * E)
{
	IEntity *tmp;

	if ((tmp = cast_entity<IEntity, IEntity>(E)))
		std::cout	<< "Entity is an IENTITY      - has id : " << tmp->getId() << std::endl;
}

void	test_IDrawable(IEntity * E)
{
	IDrawable *tmp;

	if ((tmp = cast_entity<IEntity, IDrawable>(E)))
		std::cout << "Entity is an IDRAWABLE    - has skin : " << tmp->getSkin() << std::endl;
}

void	test_IArmable(IEntity * E)
{
	IArmable *tmp;

	if ((tmp = cast_entity<IEntity, IArmable>(E)))
		std::cout << "Entity is an IARMABLE     - has power : " << tmp->getPower() << std::endl;
}

void	test_ICollidable(IEntity * E)
{
	int		x = -1;
	int		y = -1;
	ICollidable *tmp;

	if ((tmp = cast_entity<IEntity, ICollidable>(E)))
	{
		tmp->fetchLeftBorder(x, y);
		std::cout	<< "Entity is an ICOLLIDABLE  - has hitbox : "
					<< "x1 = " << tmp->getHitBox().xmin_
					<< ", y1 = " << tmp->getHitBox().ymin_
					<< ", x2 = " << tmp->getHitBox().xmax_
					<< ", y2 = " << tmp->getHitBox().ymax_
					<< std::endl;
		std::cout	<< "\t\t\t  - has leftborder : x = " << x 
					<< ", y = "	<< y << std::endl;
	}
}

void	test_IMoveable(IEntity * E)
{
	IMoveable *tmp;

	if ((tmp = cast_entity<IEntity, IMoveable>(E)))
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

	if ((tmp = cast_entity<IEntity, IDestroyable>(E)))
	{
		std::cout << "Entity is an IDESTROYABLE - has " << tmp->getLife();

		tmp->subLife(nbLost);
		std::cout	<< " Lives. It has lost " << nbLost
					<< " lives, has now " << tmp->getLife() << std::endl;
	}
}

void	test_IScriptable(IEntity * E)
{
	IScriptable *tmp;

	if ((tmp = cast_entity<IEntity, IScriptable>(E)))
	  std::cout << "Entity is an ISCRIPTABLE" << std::endl;
}

void	test_IPlayable(IEntity * E)
{
	IPlayable *tmp;

	if ((tmp = cast_entity<IEntity, IPlayable>(E)))
		std::cout	<< "Entity is an IPLAYABLE    - has pos : x =  " << tmp->getPosition().x_
					<< ", y = " << tmp->getPosition().y_ << std::endl;
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
	test_IPlayable(E);
}

int		main()
{
	int				life = 100;
	int				power = 20;
	float			speed = 0.5f;
	ePlayerSkin		ps = Player_1;
	eDecorSkin		ds = Wall_1;
	eWeaponSkin		ws = Weapon_1;
	Point			pos(42, 42);
	Point			dir(10, 10);
	HitBox			hb(50, 50, 100, 250);

	IEntity* monster = new Alien1(pos, dir); // each monster constructs itself, we just need the positions
	IEntity* decor   = new EntityDecor(ds, speed, pos, dir, hb);
	IEntity* player  = new EntityPlayer(life, power, ps, speed, pos, dir, hb);
	IEntity* weapon  = new EntityWeapon(life, power, ws, speed, pos, dir, hb);

	std::cout << "\nTesting Alien1.." << std::endl;		test_the_entity(monster);
	std::cout << "\nTesting Decor.." << std::endl;		test_the_entity(decor);
	std::cout << "\nTesting Player.." << std::endl;		test_the_entity(player);
	std::cout << "\nTesting Weapon.." << std::endl;		test_the_entity(weapon);

	for (;;);
	return 0;
}
