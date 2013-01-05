#include "Player.h"

#include <iostream> // remove

/* Used to always provide a unique value to [id_] */
int Player::currentId_ = 0;

Player::Player(void)
	: id_(currentId_++)
{
	std::cout << "--Construction Player" << std::endl;
}


Player::~Player(void)
{
	std::cout << "--Destruction Player" << std::endl;
}


int			Player::getId() const
{
	return this->id_;
}


IAccount *	Player::getAccount() const
{
	return this->account_;
}


IService *	Player::getService() const
{
	return this->service_;
}
