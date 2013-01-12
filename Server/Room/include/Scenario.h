#pragma once

#include <deque>
#include "TimePoint.h"

class Scenario
{
private:
	std::deque<TimePoint>	timePoints_;

public:
	Scenario(void);
	~Scenario(void);

public:
	bool	isOver(float t);
	void	next(float t);
};

