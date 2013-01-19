#include "EntityDecor.h"

EntityDecor::EntityDecor(eDecorSkin ds, float speed, const Point& pos,
				const Point& dir, const HitBox& hb)
	:	AEntity(),
		skin_(ds),
		speed_(speed),
		pos_(pos),
		dir_(dir),
		hb_(hb),
		id_(currentId_++)
{
}

EntityDecor::~EntityDecor()
{
}


uint16_t		EntityDecor::getId() const
{
	return this->id_;	
}


int				EntityDecor::getSkin() const
{
	return this->skin_;
}


const HitBox&	EntityDecor::getHitBox() const
{
	return this->hb_;
}


void			EntityDecor::fetchLeftBorder(int& x, int& y) const
{
	x = this->hb_.xmin_;
	y = this->hb_.ymin_;
}


const Point&	EntityDecor::getPosition() const
{
	return this->pos_;		
}


const Point&	EntityDecor::getDirection() const
{
	return this->dir_;
}


float			EntityDecor::getSpeed() const
{
	return this->speed_;
}


void			EntityDecor::setPosition(int x, int y)
{
	this->pos_.x_ = x;
	this->pos_.y_ = y;
}


void			EntityDecor::setDirection(int x, int y)
{
	this->dir_.x_ = x;
	this->dir_.y_ = y;
}


void			EntityDecor::setSpeed(float s)
{
	this->speed_ = s;
}
