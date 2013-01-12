#include "Scenario.h"

#include <iostream> // remove

Scenario::Scenario(void)
{
	std::cout << "--Construction Scenario" << std::endl;
}


Scenario::~Scenario(void)
{
	std::cout << "--Destruction Scenario" << std::endl;
}


/*TO DO*/
bool	Scenario::isOver(float)
{
	std::cout << "\n{Scenario::isOver}" << std::endl;
	return false; // remove
}


/*TO DO*/
void	Scenario::next(float)
{
	std::cout << "\n{Scenario::next}" << std::endl;
}
