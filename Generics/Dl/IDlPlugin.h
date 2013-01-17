
#pragma once
#include <string>

namespace Dl
{
	class IDlPlugin
	{
	public:
		virtual ~IDlPlugin() {}
		virtual std::string const& getId() const = 0;
	};
}