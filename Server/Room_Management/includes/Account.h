#pragma once

#include <string>

#include "IAccount.h"

class Account : public IAccount
{
private:
	int				id_;
	int				score_;
	std::string		login_;
	std::string		password_;

public:
	Account(void);
	virtual ~Account(void);

/* Methods herited from IAccount */
public:
	virtual int	getId() const;
	virtual int	getAchScore() const;
	virtual const std::string & getLogin() const;
	virtual const std::string & getPassword() const;
};

