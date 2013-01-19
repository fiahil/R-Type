#include "EntityPlayer.h"

EntityPlayer::EntityPlayer(int life, int power, ePlayerSkin skin, float speed,
							const Point& pos, const Point& dir, const HitBox& hb)
	:	AEntity(),
		life_(life),
		power_(power),
		skin_(skin),
		speed_(speed),
		pos_(pos),
		dir_(dir),
		hb_(hb),
		id_(currentId_++)
{
}

EntityPlayer::~EntityPlayer()
{
}


uint16_t		EntityPlayer::getId() const
{
	return this->id_;	
}


int				EntityPlayer::getSkin() const
{
	return this->skin_;
}


int				EntityPlayer::getPower() const
{
	return this->power_;
}


const HitBox&	EntityPlayer::getHitBox() const
{
	return this->hb_;
}


void			EntityPlayer::fetchLeftBorder(int& x, int& y) const
{
	x = this->hb_.xmin_;
	y = this->hb_.ymin_;
}


void			EntityPlayer::destroy()
{
}


int				EntityPlayer::getLife() const
{
	return this->life_;
}


void			EntityPlayer::subLife(int dmg)
{
	this->life_ -= dmg;
	if (this->life_ <= 0)
		this->destroy();
}


const Point&	EntityPlayer::getPosition() const
{
	return this->pos_;
}


void			EntityPlayer::setPosition(int x, int y)
{
	this->dir_.x_ = x;
	this->dir_.y_ = y;
}