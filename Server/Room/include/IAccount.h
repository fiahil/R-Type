#pragma once

#include <string>

class IAccount
{
public:
	virtual ~IAccount(void) {}

public:
	virtual int	getId() const = 0;
	virtual int	getAchScore() const = 0;
	virtual const std::string & getLogin() const = 0;
	virtual const std::string & getPassword() const = 0;
};