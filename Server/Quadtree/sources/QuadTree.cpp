
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

bool	QuadTree::checkCollision(ICollidable *check)
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

void	QuadTree::addShip(ICollidable *ship)
{
	const	HitBox	hit = ship->getHitBox();
	ship_.push_back(ship);
	if (hit.xmin_ < (x_ / 2) && hit.ymin_ < (y_ / 2))
		tree_[0].addEntity(ship);
	if (hit.xmin_ < (x_ / 2) && hit.ymax_ >= (y_ / 2))
		tree_[1].addEntity(ship);
	if (hit.xmax_ >= (x_ / 2) && hit.ymin_ < (y_ / 2))
		tree_[2].addEntity(ship);
	if (hit.xmax_ >= (x_ / 2) && hit.ymax_ >= (y_ / 2))
		tree_[3].addEntity(ship);
}

void	QuadTree::addEnnemy(ICollidable *ennemy)
{
	const	HitBox	hit = ennemy->getHitBox();
	ennemy_.push_back(ennemy);
	if (hit.xmin_ < (x_ / 2) && hit.ymin_ < (y_ / 2))
		tree_[0].addEntity(ennemy);
	if (hit.xmin_ < (x_ / 2) && hit.ymax_ >= (y_ / 2))
		tree_[1].addEntity(ennemy);
	if (hit.xmax_ >= (x_ / 2) && hit.ymin_ < (y_ / 2))
		tree_[2].addEntity(ennemy);
	if (hit.xmax_ >= (x_ / 2) && hit.ymax_ >= (y_ / 2))
		tree_[3].addEntity(ennemy);
}

void	QuadTree::addBullet(ICollidable *bullet)
{
	const	HitBox	hit = bullet->getHitBox();
	bullet_.push_back(bullet);
	if (hit.xmin_ < (x_ / 2) && hit.ymin_ < (y_ / 2))
		tree_[0].addEntity(bullet);
	if (hit.xmin_ < (x_ / 2) && hit.ymax_ >= (y_ / 2))
		tree_[1].addEntity(bullet);
	if (hit.xmax_ >= (x_ / 2) && hit.ymin_ < (y_ / 2))
		tree_[2].addEntity(bullet);
	if (hit.xmax_ >= (x_ / 2) && hit.ymax_ >= (y_ / 2))
		tree_[3].addEntity(bullet);
}

