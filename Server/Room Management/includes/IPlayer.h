#pragma once

#include "IAccount.h"
#include "IService.h"

class IPlayer
{
public:
	virtual ~IPlayer() {}

public:
	virtual int	getId()	const				= 0;
	virtual IAccount *	getAccount() const	= 0;
	virtual IService *	getService() const	= 0;
};