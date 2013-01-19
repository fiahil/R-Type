#include "AEntityMonster.h"

AEntityMonster::AEntityMonster(const Point& pos, const Point& dir)
	:	AEntity(),
		life_(-1),
		power_(-1),
		skin_(ErrorMonsterSkin),
		speed_(-1.0f),
		pos_(pos),
		dir_(dir),
		hb_(-1, -1, -1, -1),
		id_(currentId_++)
{
}

AEntityMonster::~AEntityMonster()
{
}


uint16_t		AEntityMonster::getId() const
{
	return this->id_;	
}


int				AEntityMonster::getSkin() const
{
	return this->skin_;
}


int				AEntityMonster::getPower() const
{
	return this->power_;
}


const HitBox&	AEntityMonster::getHitBox() const
{
	return this->hb_;
}


void			AEntityMonster::fetchLeftBorder(int& x, int& y) const
{
	x = this->hb_.xmin_;
	y = this->hb_.ymin_;
}


const Point&	AEntityMonster::getPosition() const
{
	return this->pos_;		
}


const Point&	AEntityMonster::getDirection() const
{
	return this->dir_;
}


float			AEntityMonster::getSpeed() const
{
	return this->speed_;
}


void			AEntityMonster::setPosition(int x, int y)
{
	this->pos_.x_ = x;
	this->pos_.y_ = y;
}


void			AEntityMonster::setDirection(int x, int y)
{
	this->dir_.x_ = x;
	this->dir_.y_ = y;
}


void			AEntityMonster::setSpeed(float s)
{
	this->speed_ = s;
}

void			AEntityMonster::destroy()
{
}


int				AEntityMonster::getLife() const
{
	return this->life_;
}


void			AEntityMonster::subLife(int dmg)
{
	this->life_ -= dmg;
	if (this->life_ <= 0)
		this->destroy();
}


eAction			AEntityMonster::getNextAction(float atTime) const
{
	for (std::deque<Actions>::const_iterator it = this->script_.begin();
		it != this->script_.end(); ++it)
			if ((*it).time_ == atTime)
				return (*it).action_;
	return ERRORACTION;
}
