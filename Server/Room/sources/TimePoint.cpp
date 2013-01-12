#include "TimePoint.h"

#include <iostream> // remove

TimePoint::TimePoint(void)
{
	std::cout << "--Construction TimePoint" << std::endl;
}


TimePoint::~TimePoint(void)
{
	std::cout << "--Destruction TimePoint" << std::endl;
}
