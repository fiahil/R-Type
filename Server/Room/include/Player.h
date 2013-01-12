#pragma once

#include "IPlayer.h"
#include "IAccount.h"
#include "IService.h"

class Player : public IPlayer
{
private:
	int				id_;
	bool			isPlaying_;
	std::string		name_;
	std::string		hash_;
	std::string		ep_;
	IService *		service_;
	IAccount *		account_;

/* Used to always provide a unique value to [id_] */
private:
	static int	currentId_;

private:
	Player(void);

public:
	Player(const std::string & name, const std::string & hash, IService * service);
	virtual ~Player(void);

/* Methods herited from IPlayer */
public:
	virtual bool				isPlaying()	const;
	virtual void				setStatus(bool status);
	virtual int					getId() const;
	virtual const std::string &	getName() const;
	virtual const std::string &	getHash() const;
	virtual	const std::string &	getEp() const;
	virtual void				setEp(std::string ep);
	virtual IService *			getService() const;
	virtual IAccount *			getAccount() const;
	virtual void				setAccount(IAccount * account);
};

