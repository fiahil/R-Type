#include "RegisterManager.h"

#include <iostream> // remove

RegisterManager::RegisterManager(void)
{
	std::cout << "--Construction RegisterManager" << std::endl;
}

RegisterManager::~RegisterManager(void)
{
	std::cout << "--Destruction RegisterManager" << std::endl;
}

void	RegisterManager::addAccount(IAccount *)
{
	std::cout << "\n{RoomManager::addAccount}..." << std::endl;
}

void	RegisterManager::removeAccount(int)
{
	std::cout << "\n{RoomManager::removeAccount}..." << std::endl;
}
