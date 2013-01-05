#include "GameplayEngine.h"

#include <iostream> // remove

GameplayEngine::GameplayEngine(void)
{
	std::cout << "--Construction GameplayEngine" << std::endl;
}

GameplayEngine::~GameplayEngine(void)
{
	std::cout << "--Destruction GameplayEngine" << std::endl;
}
