#include "RegisterManager.h"

#include "logger.h"

RegisterManager::RegisterManager(void)
{
	DEBUG << "--Construction RegisterManager" << std::endl;
}

RegisterManager::~RegisterManager(void)
{
	DEBUG << "--Destruction RegisterManager" << std::endl;
}

void	RegisterManager::addAccount(IAccount *)
{
	DEBUG << "{RoomManager::addAccount}..." << std::endl;
}

void	RegisterManager::removeAccount(int)
{
	DEBUG << "{RoomManager::removeAccount}..." << std::endl;
}
