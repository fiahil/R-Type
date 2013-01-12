#pragma once

#include <deque>
#include "IAccount.h"

class RegisterManager
{
private:
	std::deque<IAccount *>	accounts_;

public:
	RegisterManager(void);
	~RegisterManager(void);

public:
	void	addAccount(IAccount *a);
	void	removeAccount(int id);
};

