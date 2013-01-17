
#pragma once

#include	<Windows.h>

#include	"IMutex.h"

namespace LWP
{

class Mutex : public IMutex
{
private:
	CRITICAL_SECTION cs_;

public:
	Mutex(void);
	virtual ~Mutex(void);
	virtual void lock(void);
	virtual void unlock(void);
	virtual bool trylock(void);
};

}		// namespace LWP