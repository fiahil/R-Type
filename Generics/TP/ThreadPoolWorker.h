
#pragma once
#include "Consumer.h"
#include "Storage.h"

#ifdef WIN32
	#include "WinThread.h"
#else
	#include "UnixThread.h"
#endif

#include "IPoolSystemElement.h"

namespace TP
{
	template <class Task>
	class ThreadPoolWorker :
		public PC::Consumer<Task, PC::Storage<Task, ThreadPoolQueue<Task> > >,
		public PS::IPoolSystemElement
	{
		LWP::IThread*	thread_;
		bool			used_;

	public:
		ThreadPoolWorker()
			: PC::Consumer<Task, PC::Storage<Task, ThreadPoolQueue<Task> > >(*ThreadPool<Task>::getInstance(0)),
			thread_(new Thread(this)),
			used_(false)
		{
			this->thread_->launch();
		}

		bool	isUsed() const
		{
			return this->used_;
		}

		void	operator()()
		{
			while (true)
			{
				this->wait();
				
				Task*	t = this->consume();
				if (t != 0)
				{
					this->used_ = true;
					(*t)();
					this->used_ = false;
				}
			}
		}
	};
}