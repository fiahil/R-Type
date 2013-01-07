
#pragma once

namespace PS
{
	class IPoolSystemElement
	{
	public:
		virtual void	initialize() = 0;
		virtual bool	isUsed() const = 0;
		virtual ~IPoolSystemElement() { }
	};
}