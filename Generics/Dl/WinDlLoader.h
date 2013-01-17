
#pragma once
#include <Windows.h>
#include <string>
#include "IDlLoader.h"
#include "DlExceptions.h"

namespace Dl
{
	template <class T>
	class WinDlLoader : public IDlLoader<T>
	{
		typedef T*	(*procFunc)();
		typedef std::string	(*idProcFunc)();

		WinDlLoader(WinDlLoader const&);
		WinDlLoader & operator=(WinDlLoader const&);

		T*		object_;
		HMODULE handle_;

	public:
		WinDlLoader()
			: handle_(0), object_(0)
		{
		}

		~WinDlLoader()
		{
			if (this->handle_)
				FreeLibrary(this->handle_);
		}

		void load(std::string const& path, std::string const& entryPoint)
		{
			this->handle_ = LoadLibrary(std::wstring(path.begin(), path.end()).c_str());
			if (!this->handle_)
				throw DlLibLoadFail();
		
			procFunc ptr = reinterpret_cast<procFunc>(GetProcAddress(this->handle_, entryPoint.c_str()));
			if (!ptr)
				throw DlSymbolLoadFail();

			this->object_ = ptr();
		}

		T*	getObject(void) const
		{
			return this->object_;
		}
	};
}