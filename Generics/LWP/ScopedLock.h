
#pragma once

#include "IMutex.h"

namespace LWP
{
	class ScopedLock
	{
		IMutex*		mutex_;

	public:
		ScopedLock(IMutex*);
		~ScopedLock();
	};
}