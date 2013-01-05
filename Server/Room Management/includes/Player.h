#pragma once

#include "IPlayer.h"
#include "IAccount.h"
#include "IService.h"

class Player : public IPlayer
{
private:
	int			id_;
	IAccount *	account_;
	IService *	service_;

/* Used to always provide a unique value to [id_] */
private:
	static int	currentId_;

public:
	Player(void);
	virtual ~Player(void);

/* Methods herited from IPlayer */
public:
	virtual int	getId() const;
	virtual IAccount *	getAccount() const;
	virtual IService *	getService() const;
};

