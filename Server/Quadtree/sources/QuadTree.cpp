
#include "QuadTree.h"

QuadTree::QuadTree(int x, int y, unsigned int maxEPN, unsigned int maxDepth): x_(x), y_(y), maxEntityPerNode_(maxEPN), maxDepth_(maxDepth)
{
	int x_opti1 = x >> 4, x_opti2 = (3 * x) >> 4, x_opti3 = x >> 2, y_opti1 = y >> 4, y_opti2 = (3 * y) >> 4, y_opti3 = y >> 2;

	tree_[0].init(maxDepth, maxEPN, x_opti1, y_opti1, x_opti3, y_opti3, &collider_);
	tree_[1].init(maxDepth, maxEPN, x_opti1, y_opti2, x_opti3, y_opti3, &collider_);
	tree_[2].init(maxDepth, maxEPN, x_opti2, y_opti1, x_opti3, y_opti3, &collider_);
	tree_[3].init(maxDepth, maxEPN, x_opti2, y_opti2, x_opti3, y_opti3, &collider_);
	tree_[4].init(0, static_cast<unsigned int>(-1), 0, 0, 0, 0, &collider_);
}

QuadTree::~QuadTree()
{
}

bool	QuadTree::checkCollision(IEntity *check)
{
	bool	isDead = false;

	for (int i = 0; i < 4; ++i)
	{
		if (tree_[i].checkCollision(check))
		{
			isDead = true;
		}
	}
	return isDead;
}

void	QuadTree::addShip(IEntity *ship)
{/*
	ship_.push_back(ship);
	if (ship->getXUp() < (x_ / 2) && ship->getYLeft() < (y_ / 2))
		tree_[0].addEntity(ship);
	if (ship->getXUp() < (x_ / 2) && ship->getYLeft() >= (y_ / 2))
		tree_[1].addEntity(ship);
	if (ship->getXUp() >= (x_ / 2) && ship->getYLeft() < (y_ / 2))
		tree_[2].addEntity(ship);
	if (ship->getXUp() >= (x_ / 2) && ship->getYLeft() >= (y_ / 2))
		tree_[3].addEntity(ship);
		*/
}

void	QuadTree::addEnnemy(IEntity *ennemy)
{
	/*
	ennemy_.push_back(ennemy);
	if (ennemy->getXDown() < (x_ / 2) && ennemy->getYLeft() < (y_ / 2))
		tree_[0].addEntity(ennemy);
	if (ennemy->getXDown() < (x_ / 2) && ennemy->getYRight() >= (y_ / 2))
		tree_[1].addEntity(ennemy);
	if (ennemy->getXUp() >= (x_ / 2) && ennemy->getYLeft() < (y_ / 2))
		tree_[2].addEntity(ennemy);
	if (ennemy->getXUp() >= (x_ / 2) && ennemy->getYRight() >= (y_ / 2))
		tree_[3].addEntity(ennemy);
		*/
}

void	QuadTree::addBullet(IEntity *bullet)
{
	bullet_.push_back(bullet);
}

