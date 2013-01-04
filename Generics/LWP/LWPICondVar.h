
#pragma once

namespace LWP
{
	class ICondVar
	{
	public:
		virtual void	wait() = 0;
		virtual void	signal() = 0;
		virtual void	broadcast() = 0;
		virtual ~ICondVar() {}
	};
}