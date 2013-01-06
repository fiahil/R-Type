
#pragma once

namespace PS
{
	class IPoolSystemElement
	{
	public:
		virtual bool	isUsed() const = 0;
		virtual ~IPoolSystemElement() { }
	};
}