
#pragma once

#include	<algorithm>
#include	<list>
#include	"ICollidable.h"
#include	"Collider.h"

class Node
{
	Node						*leaf_;
	Collider					*collider_;
	bool						isLast_;
	std::list<ICollidable*>			items_;
	int							maxDepth_;
	unsigned int				maxEntity_;
	int							centerX_;
	int							centerY_;
	int							sizeX_;
	int							sizeY_;

	void	autoSplit();

public:
	Node();
	Node(int, unsigned int, int, int, int, int, Collider*);
	Node(int, unsigned int, Collider*);
	~Node();
	void	addEntity(ICollidable*);
	bool	checkCollision(ICollidable *);
	void	setCenterX(int);
	void	setCenterY(int);
	void	setSizeX(int);
	void	setSizeY(int);
	void	clear();
	void	init(int, unsigned int, int, int, int, int, Collider*);
};

