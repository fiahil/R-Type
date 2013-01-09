
#pragma once

#include <list>
#include <algorithm>
#include "IPoolSystemElement.h"

namespace PS
{
	/*
	** Template parameter must be derived from PoolSystemElement
	*/
	template <class T>
	class PoolSystem
	{
		static bool		notUsed(IPoolSystemElement* e)
		{
			return !e->isUsed();
		}

		static bool		isUsed(IPoolSystemElement* e)
		{
			return e->isUsed();
		}

		size_t							chunkSize_;
		std::list<IPoolSystemElement*>	elements_;

	public:
		PoolSystem(size_t chunkSize)
			: chunkSize_(chunkSize)
		{
		}

		void	allocate()
		{
			for (size_t i = 0; i < this->chunkSize_; ++i)
			{
				T* pse = new T();
				pse->initialize();
				this->elements_.push_back(pse);
			}
		}

		void	clean()
		{
			size_t	s = std::count_if(this->elements_.begin(), this->elements_.end(), &PoolSystem<T>::notUsed);

			int eltnum = (s / this->chunkSize_) * this->chunkSize_;
			
			for (auto it = this->elements_.begin();
				it != this->elements_.end() && eltnum > 0;
				--eltnum)
			{
				if (!(*it)->isUsed())
				{
					delete *it;
					*it = 0;
					it = this->elements_.erase(it);
				}
				else
					++it;
			}
			
				while (s >= this->chunkSize_)
			{
				this->elements_.remove_if(&PoolSystem<T>::notUsed);

				s -= this->chunkSize_;
			}
		}

		bool	isSaturated() const
		{
			return (std::count_if(this->elements_.begin(), this->elements_.end(), &PoolSystem<T>::isUsed) == this->elements_.size());
		}

		size_t	poolSize() const
		{
			return this->elements_.size();
		}

		T*		peek() const
		{
			auto it = std::find_if(this->elements_.begin(), this->elements_.end(), &PoolSystem<T>::notUsed);
			if (it != this->elements_.end())
				return dynamic_cast<T*>(*it);
			return 0;
		}
	};
}