#pragma once

typedef struct	s_Point
{
	int	x_;
	int	y_;
} Point;

class IEntity
{
public:
	virtual ~IEntity(void) {}

public:
	virtual const Point & getPos() const = 0;
};
