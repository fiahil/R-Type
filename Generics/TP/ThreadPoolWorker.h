
#pragma once
#include "Consumer.h"
#include "Storage.h"

#ifdef WIN32
	#include "WinThread.h"
#else
	#include "UnixThread.h"
#endif

#define THREADPOOLWORKER__H

#include "IPoolSystemElement.h"
#include "ThreadPoolQueue.h"
#include "ThreadPool.h"

namespace TP
{

	template <class Task>
	class ThreadPoolWorker :
		public PC::Consumer<Task, PC::Storage<Task, ThreadPoolQueue<Task>, LWP::CondVar> >,
		public PS::IPoolSystemElement
	{
		volatile bool*	used_;
		LWP::IThread*	thread_;

	public:
		ThreadPoolWorker()
			: PC::Consumer<Task, PC::Storage<Task, ThreadPoolQueue<Task>, LWP::CondVar> >(ThreadPool<Task>::getInstance(0)),
			used_(new bool(false))
		{
			this->thread_ = new LWP::Thread<ThreadPoolWorker>(*this);
		}

		void	initialize()
		{
			this->thread_->launch();
		}

		bool	isUsed() const
		{
			return *this->used_;
		}

		void	operator()()
		{
			while (true)
			{
				this->wait();
				
				Task* t = 0;
				while ((t = this->consume()) != 0)
				{
					*this->used_ = true;
					(*t)();
					*this->used_ = false;
				}
			}
		}
	};
}
