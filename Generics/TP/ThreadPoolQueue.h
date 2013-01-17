
#pragma once
#include "SafeQueue.h"

#ifdef WIN32
	#include "WinMutex.h"
#else
	#include "UnixMutex.h"
#endif

namespace TP
{
	template <class T>
	class ThreadPoolQueue : public LWP::SafeQueue<T*>
	{
	public:
		ThreadPoolQueue()
			: LWP::SafeQueue<T*>(new LWP::Mutex())
		{
		}

		T*	pop()
		{
			T*	data = 0;

			this->tryPop(data);
			return data;
		}
	};
}