
#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include "IDlLoader.h"

#ifdef WIN32
#include "WinDlLoader.h"
#else
#include "LinDlLoader.h"
#endif

/*
 * Dl Module
 * ---------
 *
 * Description
 * - This module provide a high-level plugin management class (DlManager)
 *   and a dynamic library abstraction (DlLoader)
 *
 * Requirements
 * - DlManager template parameter MUST implement IDlPlugin interface
 */

namespace Dl
{
	template <class T>
	class DlManager
	{
		DlManager&	operator=(DlManager const&);
		DlManager(DlManager const&);

		std::map<std::string, IDlLoader<T>*>	dlls_;

	public:
		DlManager()
		{
		}

		~DlManager()
		{
			std::for_each(this->dlls_.begin(), this->dlls_.end(),
				[] (std::pair<std::string, IDlLoader<T>*> const& p)
			{
				delete p.second;
			});
		}

		bool	loadPlugin(std::string const& path)
		{
#ifdef	WIN32
			IDlLoader<T> *	lib = new WinDlLoader<T>();
#else
			IDlLoader<T> *	lib = new LinDlLoader<T>();
#endif
			lib->load(path, "entryPoint");

			if (!(this->dlls_.insert(std::make_pair(lib->getObject()->getId(), lib))).second)
			{
				delete lib;
				return false;
			}
			return true;
		}

		T*		getObject(std::string const& id) const
		{
			T *	tmp = 0;

			std::for_each(this->dlls_.begin(), this->dlls_.end(),
				[&] (std::pair<std::string, IDlLoader<T>*> const& p)
			{
				if (id == p.first)
					tmp = p.second->getObject();
			});
			return tmp;
		}

		bool	isPluginLoaded(std::string const& id) const
		{
			return this->dlls_.find(id) != this->dlls_.end();
		}
	};
}
