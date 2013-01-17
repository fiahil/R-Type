
#pragma once
#include <queue>

namespace PC
{
	/*
	** `Notifier' class MUST implement the following methods :
	** - void wait();
	** - void notify();
	**
	** `Container' class MUST implement the following methods :
	** - void push(Packet*);
	** - Packet* pop();
	**
	** `Container' parameter MUST be set with `Packet*' if needed (ex: std::queue<Packet*>)
	*/
	template <class Packet, class Container, class Notifier>
	class Storage : public Notifier
	{
	protected:
		Container	container_;

	public:
		Storage()
			: Notifier(),
			container_()
		{
		}
	
		void		store(Packet* p)
		{
			this->container_.push(p);
		}

		Packet*		grab()
		{
			return this->container_.pop();
		}

		size_t		storageSize() const
		{
			return this->container_.size();
		}
	};

	template <class T>
	class basicQueue : public std::queue<T>
	{
	public:
		T		pop()
		{
			T data = this->front();
			std::queue<T>::pop();
			return data;
		}
	};
}