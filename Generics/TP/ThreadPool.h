
#pragma once
#include "Storage.h"
#include "Producer.h"

#ifdef WIN32
	#include "WinCondVar.h"
	#include "WinMutex.h"
#else
	#include "UnixCondVar.h"
	#include "UnixMutex.h"
#endif

#include "PoolSystem.h"

#include "ThreadPoolWorker.h"
#include "ThreadPoolQueue.h"

namespace TP
{
	/*
	** Task MUST implement :
	** - void operator()(void)
	*/
	template <class Task>
	class ThreadPool :
		public PC::Storage<Task, ThreadPoolQueue<Task>, LWP::ICondVar>,
		public PC::Producer<Task, PC::Storage<Task, ThreadPoolQueue<Task>, LWP::ICondVar> >,
		public PS::PoolSystem<ThreadPoolWorker<Task> >
	{
		static ThreadPool<Task>*	Instance;

		ThreadPool(size_t n)
			: PC::Storage<Task, ThreadPoolQueue<Task>, LWP::ICondVar>(),
			PC::Producer<Task, PC::Storage<Task, ThreadPoolQueue<Task>, LWP::ICondVar> >(this),
			PS::PoolSystem<ThreadPoolWorker<Task> >(n)
		{
			ThreadPool<Task>::Instance = this;
		}

	public:
		static ThreadPool<Task>*	getInstance(size_t n)
		{
			if (ThreadPool<Task>::Instance == 0)
				{
					ThreadPool<Task>::Instance = new ThreadPool<Task>(n);
					ThreadPool<Task>::Instance->allocate();
				}
			return ThreadPool<Task>::Instance;
		}

		void	push(Task* t)
		{
			PC::Producer<Task, PC::Storage<Task, ThreadPoolQueue<Task>, LWP::ICondVar> >::produce(t);
		}
	};

	template <class Task>
	ThreadPool<Task>* ThreadPool<Task>::Instance = 0;
}