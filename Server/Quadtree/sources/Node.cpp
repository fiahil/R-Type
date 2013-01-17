#include "Node.h"

Node::Node()
{
	leaf_ = 0;
}

Node::Node(int maxDepth, unsigned int maxEntity,
		   int centerX, int centerY,
		   int sizeX, int sizeY, Collider* collider)
		   : collider_(collider), maxDepth_(maxDepth), maxEntity_(maxEntity),
			 centerX_(centerX), centerY_(centerY),
			 sizeX_(sizeX), sizeY_(sizeY)
									
{
	leaf_ = 0;
}

Node::Node(int maxDepth, unsigned int maxEntity, Collider* collider)
		   : collider_(collider), maxDepth_(maxDepth), maxEntity_(maxEntity),
			 centerX_(0), centerY_(0),
			 sizeX_(0), sizeY_(0)				
{
	leaf_ = 0;
}

Node::~Node()
{
	if (leaf_)
		delete[] leaf_;
}

void	Node::init(int maxDepth, unsigned int maxEntity,
				   int centerX, int centerY,
				   int sizeX, int sizeY, Collider* collider)
{
	collider_ = collider;
	maxDepth_ = maxDepth;
	maxEntity_ = maxEntity;
	centerX_ = centerX;
	centerY_ = centerY;
	sizeX_ = sizeX;
	sizeY_ = sizeY;
}

void	Node::clear()
{
	for (std::list<IEntity *>::iterator it = items_.begin(); it != items_.end();)
	{
		items_.erase(it);
	}
}

void	Node::autoSplit()
{
	if (!leaf_)
	{
		leaf_ = new Node[4];
		
		leaf_[0].init(maxDepth_ - 1, maxEntity_, centerX_ - (sizeX_ / 4), centerY_ - (sizeY_ / 4), sizeX_ / 2, sizeX_ / 2, collider_);
		leaf_[1].init(maxDepth_ - 1, maxEntity_, centerX_ + (sizeX_ / 4), centerY_ - (sizeY_ / 4), sizeX_ / 2, sizeX_ / 2, collider_);
		leaf_[2].init(maxDepth_ - 1, maxEntity_, centerX_ - (sizeX_ / 4), centerY_ + (sizeY_ / 4), sizeX_ / 2, sizeX_ / 2, collider_);
		leaf_[3].init(maxDepth_ - 1, maxEntity_, centerX_ + (sizeX_ / 4), centerY_ + (sizeY_ / 4), sizeX_ / 2, sizeX_ / 2, collider_);
	}

	for (int i = 0; i < 4; ++i)
		leaf_[i].clear();
	
	for (std::list<IEntity *>::iterator it = items_.begin();
		 it != items_.end();
		 ++it)
	{
		int x, y;
		(*it)->getPos(x, y);

		if ((*it)->getXDown() <= centerX_ && (*it)->getYLeft() <= centerY_)
			leaf_[0].addEntity(*it);
		if ((*it)->getXDown() <= centerX_ && (*it)->getYRight() > centerY_)
			leaf_[1].addEntity(*it);
		if ((*it)->getXUp() > centerX_ && (*it)->getYLeft() <= centerY_)
			leaf_[2].addEntity(*it);
		if ((*it)->getXUp() > centerX_ && (*it)->getYRight() > centerY_)
			leaf_[3].addEntity(*it);
	} 
}

void	Node::addEntity(IEntity *entity)
{
	if (isLast_)
	{
		items_.push_back(entity);
		if (maxDepth_ && items_.size() > maxEntity_)
			autoSplit();
	}
}

bool	Node::checkCollision(IEntity * check)
{
	bool	collision = false;
	
	if (items_.size() <= maxEntity_)
	{
		if (std::find(items_.begin(), items_.end(), check) != items_.end())
		{
			collision = collider_->collide(items_, check);
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
			collision |= leaf_[i].checkCollision(check);
	}

	return collision;
}

void	Node::setCenterX(int x)
{
	centerX_ = x;
}

void	Node::setCenterY(int y)
{
	centerY_ = y;
}

void	Node::setSizeX(int x)
{
	sizeX_ = x;
}

void	Node::setSizeY(int y)
{
	sizeY_ = y;
}