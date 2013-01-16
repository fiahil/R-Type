
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

#include "ThreadPoolQueue.h"

namespace TP
{
  template<typename T> class ThreadPoolWorker;
	/*
	** Task MUST implement :
	** - void operator()(void)
	*/
	template <class Task>
	class ThreadPool :
		virtual public PC::Storage<Task, ThreadPoolQueue<Task>, LWP::CondVar>,
		virtual private PC::Producer<Task, PC::Storage<Task, ThreadPoolQueue<Task>, LWP::CondVar> >,
		virtual private PS::PoolSystem<ThreadPoolWorker<Task> >
	{
		static ThreadPool<Task>*	Instance;

		ThreadPool(size_t n)
			: PC::Storage<Task, ThreadPoolQueue<Task>, LWP::CondVar>(),
			PC::Producer<Task, PC::Storage<Task, ThreadPoolQueue<Task>, LWP::CondVar> >(this),
			PS::PoolSystem<ThreadPoolWorker<Task> >(n)
		{
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
			this->produce(t);
		}

		using PS::PoolSystem<ThreadPoolWorker<Task> >::poolSize;
		using PS::PoolSystem<ThreadPoolWorker<Task> >::isSaturated;
		using PS::PoolSystem<ThreadPoolWorker<Task> >::clean;
		using PS::PoolSystem<ThreadPoolWorker<Task> >::allocate;
	};

	template <class Task>
	ThreadPool<Task>* ThreadPool<Task>::Instance = 0;
}

#ifndef THREADPOOLWORKER__H
# include "ThreadPoolWorker.h"
#endif
