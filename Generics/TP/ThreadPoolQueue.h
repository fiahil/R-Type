
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
	class ThreadPoolQueue
	{
		IMutex*				mutex_;
		LWP::SafeQueue<T*>	queue_;

	public:
		ThreadPoolQueue()
			: mutex_(new LWP::Mutex()), queue_(mutex_)
		{
		}

		~ThreadPoolQueue()
		{
			delete this->mutex_;
		}

		T*	pop()
		{
			T*	data = 0;

			this->queue_.tryPop(data);
			return data;
		}
	};
}