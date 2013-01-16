#include "Account.h"

#include "logger.h"

Account::Account(void)
{
	DEBUG << "--Construction Account" << std::endl;
}

Account::~Account(void)
{
	DEBUG << "--Destruction Account" << std::endl;
}

int		Account::getId() const
{
	return this->id_;
}

int		Account::getAchScore() const
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