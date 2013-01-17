
#include "ScopedLock.h"

namespace LWP
{
	ScopedLock::ScopedLock(IMutex* mutex)
		: mutex_(mutex)
	{
		this->mutex_->lock();
	}

	ScopedLock::~ScopedLock()
	{
		this->mutex_->unlock();
	}
}