
#pragma once

namespace LWP
{
	class IThread
	{
	public:
		virtual bool	isWorking() const = 0;
		virtual void	launch() = 0;
		virtual void	join() = 0;
		virtual ~IThread() {}
	};
}