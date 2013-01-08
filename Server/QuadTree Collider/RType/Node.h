
#pragma once

#include	<algorithm>
#include	<list>
#include	"Collider.h"

class Node
{
	Node						*leaf_;
	Collider					*collider_;
	bool						isLast_;
	std::list<IEntity*>			items_;
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
	void	addEntity(IEntity*);
	bool	checkCollision(IEntity *);
	void	setCenterX(int);
	void	setCenterY(int);
	void	setSizeX(int);
	void	setSizeY(int);
	void	clear();
	void	init(int, unsigned int, int, int, int, int, Collider*);
};

