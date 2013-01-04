
#pragma once
#include <exception>

namespace Dl
{
	class DlLibLoadFail : public std::exception
	{
	public:
		virtual char const* what() const throw()
		{
			return "Fail to load library.";
		}
	};

	class DlSymbolLoadFail : public std::exception
	{
	public:
		virtual char const* what() const throw()
		{
			return "Fail to load symbol.";
		}
	};
}