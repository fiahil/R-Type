
#pragma once
#include "LWPIMutex.h"

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