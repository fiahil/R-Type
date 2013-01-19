#pragma once

class IPlayable
{
public:
	virtual ~IPlayable(void) {}

public:
	virtual const Point&	getPosition() const				= 0;
	virtual void			setPosition(int x, int y)		= 0;
};
