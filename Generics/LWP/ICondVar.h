
#pragma once

namespace LWP
{
	class ICondVar
	{
	public:
		virtual void	wait() = 0;
		virtual void	notify() = 0;
		virtual void	broadcast() = 0;
		virtual ~ICondVar() {}
	};
}