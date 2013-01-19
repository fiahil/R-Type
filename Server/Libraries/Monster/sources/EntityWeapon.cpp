#include "EntityWeapon.h"

EntityWeapon::EntityWeapon(int life, int power, eWeaponSkin skin, float speed,
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

EntityWeapon::~EntityWeapon()
{
}


uint16_t		EntityWeapon::getId() const
{
	return this->id_;	
}


int				EntityWeapon::getSkin() const
{
	return this->skin_;
}


int				EntityWeapon::getPower() const
{
	return this->power_;
}


const HitBox&	EntityWeapon::getHitBox() const
{
	return this->hb_;
}


void			EntityWeapon::fetchLeftBorder(int& x, int& y) const
{
	x = this->hb_.xmin_;
	y = this->hb_.ymin_;
}


const Point&	EntityWeapon::getPosition() const
{
	return this->pos_;		
}


const Point&	EntityWeapon::getDirection() const
{
	return this->dir_;
}


float			EntityWeapon::getSpeed() const
{
	return this->speed_;
}


void			EntityWeapon::setPosition(int x, int y)
{
	this->pos_.x_ = x;
	this->pos_.y_ = y;
}


void			EntityWeapon::setDirection(int x, int y)
{
	this->dir_.x_ = x;
	this->dir_.y_ = y;
}


void			EntityWeapon::setSpeed(float s)
{
	this->speed_ = s;
}


void			EntityWeapon::destroy()
{
}


int				EntityWeapon::getLife() const
{
	return this->life_;
}


void			EntityWeapon::subLife(int dmg)
{
	this->life_ -= dmg;
	if (this->life_ <= 0)
		this->destroy();
}