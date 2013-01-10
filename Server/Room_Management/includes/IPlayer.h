#pragma once

#include <string>

#include "IAccount.h"
#include "IService.hpp"

class IPlayer
{
public:
	virtual ~IPlayer() {}

public:
	virtual bool				isPlaying()	const				= 0;
	virtual void				setStatus(bool status)			= 0;
	virtual int					getId()	const					= 0;
	virtual	const std::string &	getName() const					= 0;
	virtual	const std::string &	getHash() const					= 0;
	virtual	const std::string &	getEp() const					= 0;
	virtual void				setEp(std::string ep)			= 0;
	virtual IService *			getService() const				= 0;
	virtual IAccount *			getAccount() const				= 0;
	virtual void				setAccount(IAccount * account)	= 0;

};
