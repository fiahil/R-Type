
#include	"IEntity.h"
#include	"Collider.h"
#include	"Node.h"
#include	"QuadTree.h"

#include <iostream>

int main()
{
	QuadTree test(800, 600, 5, 4);

	//              {top left coord}	{size x, y}
	IEntity	quentin(42, 42,				22, 22);
	IEntity	matthieu(21, 21, 20, 20);
	IEntity	magere(60, 60, 20, 20);
	IEntity	touloubite(0, 0, 800, 600);
	IEntity	papy(43, 43, 1, 1);
	
	test.addShip(&quentin);
	test.addEnnemy(&matthieu);
	//test.addEnnemy(&touloubite);
	//test.addEnnemy(&magere);
	//test.addEnnemy(&papy);

	// quentin shoul collide with everyone except matthieu
	// 1 = collide; 0 = not collide

	std::cout << test.checkCollision(&quentin) << std::endl;

	return (0);
}