
#pragma once

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
		Container	container_;

	public:
		Storage()
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

		size_t		size() const
		{
			return this->container_.size();
		}
	};
}