#pragma once

#include	"Node.h"
#include	"Collider.h"

class QuadTree
{
	Node					tree_[5]; // 0: TL, 1: TR, 2: BL, 3: BR, 4: LoadingZone
	Collider				collider_;
	std::list<ICollidable *>	ship_;
	std::list<ICollidable *>	bullet_;
	std::list<ICollidable *>	ennemy_;
	int						x_;
	int						y_;
	unsigned int			maxEntityPerNode_;
	unsigned int			maxDepth_;

public:
	QuadTree(int x, int y, unsigned int maxEPN, unsigned int maxDepth);
	~QuadTree();
	bool					checkCollision(ICollidable *);
	void					addEnnemy(ICollidable *);
	void					addShip(ICollidable *);
	void					addBullet(ICollidable *);
};