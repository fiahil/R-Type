
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
		size_t							chunkSize_;
		std::list<IPoolSystemElement*>	elements_;

	public:
		PoolSystem(size_t chunkSize)
			: chunkSize_(chunkSize)
		{
			allocate();
		}

		void	allocate()
		{
			for (size_t i = 0; i < this->chunkSize_; ++i)
			{
				this->elements_.push_back(new T());
			}
		}

		void	clean()
		{
			size_t	s = std::count_if(this->elements_.begin(), this->elements_.end(),
				[] (IPoolSystemElement* e)
					{
						return !e->isUsed();
					});

			int eltnum = (s / this->chunkSize_) * this->chunkSize_;
			
			for (auto it = this->elements_.begin();
				it != this->elements_.end() && eltnum > 0;
				++it, --eltnum)
			{
				if (!(*it)->isUsed())
				{
					delete *it;
					*it = 0;
					it = this->elements_.erase(it);
				}
			}
			
				while (s >= this->chunkSize_)
			{
				this->elements_.remove_if(
					[] (IPoolSystemElement* e)
						{
							return !e->isUsed();
						});

				s -= this->chunkSize_;
			}
		}

		bool	isSaturated() const
		{
			return (std::count_if(this->elements_.begin(), this->elements_.end(),
				[] (IPoolSystemElement* e)
					{
						return e->isUsed();
					}) == this->elements_.size());
		}

		size_t	size() const
		{
			return this->elements_.size();
		}

		T*		peek() const
		{
			auto it = std::find_if(this->elements_.begin(), this->elements_.end(),
				[] (IPoolSystemElement* e)
					{
						return !e->isUsed();
					});
			if (it != this->elements_.end())
				return dynamic_cast<T*>(*it);
			return 0;
		}
	};
}