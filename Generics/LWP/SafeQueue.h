
#pragma once

#include <queue>
#include "IMutex.h"
#include "ScopedLock.h"

namespace LWP
{
	template<class T>
	class SafeQueue
	{
	private :
		std::queue<T>	queue_;
		IMutex*			mutex_;

	public :
		SafeQueue(IMutex* mutex)
			: mutex_(mutex)
		{
		}

		~SafeQueue()
		{
			delete this->mutex_;
		}

		T		front()
		{
			ScopedLock	sl(this->mutex_);
		
			return this->queue_.front();
		}

		bool	tryPop(T &ret)
		{
			ScopedLock	sl(this->mutex_);

			if (!this->queue_.empty())
			{
				ret = this->queue_.front();
				this->queue_.pop();
				return true;
			}
			return false;
		}

		bool	empty()
		{
			ScopedLock	sl(this->mutex_);

			return this->queue_.empty();
		}

		void	push(T elem)
		{
			ScopedLock	sl(this->mutex_);

			this->queue_.push(elem);
		}

		size_t	size() const
		{
			ScopedLock	sl(this->mutex_);
		
			return this->queue_.size();
		}
	};

}
