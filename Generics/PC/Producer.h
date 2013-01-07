
#pragma once
#include "Storage.h"

namespace PC
{
	/*
	** `Packet' class MUST be default-constructible.
	** `Storage' class is a shorcut to the Storage<T, U, V> class.
	*/
	template <class Packet, class Storage>
	class Producer
	{
		Storage*	storage_;

	public:
		Producer(Storage* s)
			: storage_(s)
		{
		}

		void	produce(size_t n)
		{
			for (size_t i = 0; i < n; i++)
			{
				this->storage_->store(new Packet());
			}
			this->storage_->notify();
		}

		void	produce(Packet* packet)
		{
			this->storage_->store(packet);
			this->storage_->notify();
		}
	};
}