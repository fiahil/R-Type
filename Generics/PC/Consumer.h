
#pragma once
#include "Storage.h"

namespace PC
{
	/*
	** `Storage' class is a shorcut to the Storage<T, U, V> class.
	*/
	template <class Packet, class Storage>
	class Consumer
	{
		Storage&	storage_;

	public:
		Consumer(Storage& s)
			: storage_(s)
		{
		}

		Packet*	consume()
		{
			return this->storage_.grab();
		}

		void	wait()
		{
			this->storage_.wait();
		}
	};
}