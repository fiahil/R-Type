#include "Account.h"

#include <iostream> // remove

Account::Account(void)
{
	std::cout << "--Construction Account" << std::endl;
}

Account::~Account(void)
{
	std::cout << "--Destruction Account" << std::endl;
}

int					Account::getId() const
{
	return this->id_;
}

int					Account::getAchScore() const
{
	return this->score_;
}

const std::string & Account::getLogin() const
{
	return this->login_;
}

const std::string & Account::getPassword() const
{
	return this->password_;
}