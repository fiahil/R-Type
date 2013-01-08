
#include	"IEntity.h"
#include	"Collider.h"
#include	"Node.h"
#include	"QuadTree.h"

#include <iostream>

int main()
{
	QuadTree test(800, 600, 5, 4);

	IEntity	quentin(42, 42, 23, 23);
	IEntity	matthieu(21, 21, 20, 20);
	IEntity	magere(60, 60, 20, 20);
	
	test.addShip(&quentin);
	test.addEnnemy(&matthieu);
	test.addEnnemy(&magere);

	std::cout << test.checkCollision(&quentin) << std::endl;

	return (0);
}