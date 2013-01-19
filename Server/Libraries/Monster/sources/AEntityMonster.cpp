#include "AMonster.h"

AMonster::AMonster(const Point&, const Point&)
	:	life_(0),
		power_(0),
		skin_(ErrorSkin),
		speed_(0.0f),
		pos_(0, 0),
		dir_(0, 0),
		hb_(0, 0, 0, 0)
{
}

AMonster::~AMonster()
{
}


void			AMonster::fetchLeftBorder(int& x, int& y) const
{
	x = this->hb_.xmin_;
	y = this->hb_.ymin_;
}


int				AMonster::getSkin() const
{
	return this->skin_;
}


int				AMonster::getPower() const
{
	return this->power_;
}


const HitBox&	AMonster::getHitBox() const
{
	return this->hb_;
}


const Point&	AMonster::getDirection() const
{
	return this->dir_;
}


float			AMonster::getSpeed() const
{
	return this->speed_;
}


void			AMonster::destroy()
{
	//
}


int				AMonster::getLife() const
{
	return this->life_;
}


void			AMonster::subLife(int dmg)
{
	this->life_ -= dmg;
	if (this->life_ <= 0)
		this->destroy();
}


eAction			AMonster::getNextAction(float atTime) const
{
	for (std::deque<Actions>::const_iterator it = this->script_.begin();
		it != this->script_.end(); ++it)
			if ((*it).time_ == atTime)
				return (*it).action_;
	return (ERROR);
}
