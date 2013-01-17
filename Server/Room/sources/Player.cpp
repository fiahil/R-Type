#include "Player.h"
#include "deleteObj.h"

#include "logger.h"

#ifdef _WIN32 
	#include "WinMutex.h"
#else
	#include "UnixMutex.h"
#endif

/* Used to always provide a unique value to [id_] */
int Player::currentId_ = 0;

Player::Player(const std::string & name, const std::string & hash, IService * service)
	:	id_(currentId_++),
		isPlaying_(false),
		name_(name),
		hash_(hash),
		service_(service),
		account_(0),
		mutex_(0)	
{
	this->mutex_ = new LWP::Mutex();

	DEBUG << "--Construction Player" << std::endl;
}


Player::~Player(void)
{
	deleteObject<LWP::IMutex>(this->mutex_);	

	DEBUG << "--Destruction Player" << std::endl;
}


bool			Player::isPlaying()	const
{
	return this->isPlaying_;
}


void			Player::setStatus(bool status)
{
	this->isPlaying_ = status;
}


int				Player::getId() const
{
	return this->id_;
}


const std::string &	Player::getName() const
{
	return this->name_;
}


const std::string &	Player::getHash() const
{
	return this->hash_;
}


const std::string &	Player::getEp() const
{
	return this->ep_;
}


void				Player::setEp(std::string ep)
{
	this->ep_ = ep;
}


IService *		Player::getService() const
{
	return this->service_;
}


IAccount *		Player::getAccount() const
{
	return this->account_;
}


void			Player::setAccount(IAccount * account)
{
	if (account)
		this->account_ = account;
}
