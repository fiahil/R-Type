#pragma once

struct	Position
{
	int	x_;
	int	y_;
};

class IEntity
{
public:
	virtual ~IEntity(void) {}

public:
	virtual const Position & getPos() const = 0;
};