<<<<<<< HEAD
#pragma once

#include "IPlayer.h"
#include "IAccount.h"
#include "IService.h"
#include "IMutex.h"
#include "IEntity.h"

struct	ShipInfo
{
	int				pv_;
	int				dmg_;
	int				score_;
	float			speed_;
	/* Position		pos_; */
	std::string		spritePath_;
};

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
	LWP::IMutex *	mutex_;
	ShipInfo		info_;

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
=======
#pragma once

#include "IPlayer.h"
#include "IAccount.h"
#include "IService.h"
#include "IMutex.h"
#include "IEntity.h"

struct	ShipInfo
{
	int				pv_;
	int				dmg_;
	int				score_;
	float			speed_;
//	Position		pos_;
	std::string		spritePath_;
};

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
	LWP::IMutex *	mutex_;
	ShipInfo		info_;

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
>>>>>>> [Service] Patch
