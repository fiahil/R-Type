
#pragma once
#include <string>

namespace Dl
{
	template <class T>
	class IDlLoader
	{
	public:
		virtual ~IDlLoader() {}

		virtual void	load(std::string const& path, std::string const& entryPoint) = 0;
		virtual T*		getObject(void) const = 0;
	};
}