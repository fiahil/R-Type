
#include	"WinMutex.h"

namespace LWP
{

Mutex::Mutex(void)
{
	InitializeCriticalSection(&this->cs_);
}

Mutex::~Mutex(void)
{
	DeleteCriticalSection(&this->cs_);
}

void Mutex::lock(void)
{
	EnterCriticalSection(&this->cs_);
}

void Mutex::unlock(void)
{
	LeaveCriticalSection(&this->cs_);
}

bool Mutex::trylock(void)
{
	return (TryEnterCriticalSection(&this->cs_) ? true : false);
}

}		// namespace LWP