#pragma once

#include "IEntity.h"

struct	Point
{
	int	x_;
	int	y_;

	Point(int x, int y)
		:	x_(x), y_(y) {}

	Point(const Point& other)
		:	x_(other.x_), y_(other.y_) {}
};

class IMoveable
{
public:
  virtual ~IMoveable(void) {}

public:
	virtual const Point&	getPosition() const			= 0;
	virtual const Point&	getDirection() const		= 0;
	virtual float			getSpeed() const			= 0;

	virtual void			setPosition(int x, int y)	= 0;
	virtual void			setDirection(int x, int y)	= 0;
	virtual void			setSpeed(float s)			= 0;
};
