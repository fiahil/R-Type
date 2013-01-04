


#pragma once

#ifndef __LINDLLOADER_H__
#define __LINDLLOADER_H__

#include <string>
#include <dlfcn.h>
#include "IDlLoader.h"
#include "DlExceptions.h"

namespace Dl
{
	template <class T>
	class LinDlLoader : public IDlLoader<T>
	{
		typedef T*	(*procFunc)();
		typedef std::string	(*idProcFunc)();

		LinDlLoader(LinDlLoader const&);
		LinDlLoader & operator=(LinDlLoader const&);

		T*		object_;
		void*		handle_;

	public:
		LinDlLoader()
			: handle_(0), object_(0)
		{
		}

		~LinDlLoader()
		{
			if (this->handle_)
			  dlclose(this->handle_);
		}

		void load(std::string const& path, std::string const& entryPoint)
		{
		  this->handle_ = dlopen(std::string(path.begin(), path.end()).c_str(), RTLD_LAZY);
			if (!this->handle_)
				throw DlLibLoadFail();

			procFunc ptr = reinterpret_cast<procFunc>(dlsym(this->handle_, entryPoint.c_str()));
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
#endif /* __LINDLLOADER_H__ */
