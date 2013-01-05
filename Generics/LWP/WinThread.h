
#pragma once

#include	<windows.h>
#include	<string>

#include	"IThread.h"

namespace	LWP
{

template<typename T> class Thread : public IThread
{
private:
	HANDLE thread_;
	DWORD id_;
	bool isWorking_;
	T function_;

	Thread(void);
	static DWORD WINAPI threadProc(void* t)
	{
		reinterpret_cast<Thread<T>*>(t)->function_();
		return (S_OK);
	}

public:
	Thread(T function) : function_(function)
	{
		this->isWorking_ = false;
	}

	virtual ~Thread(void)
	{
		TerminateThread(this->thread_, 0);
	}

	virtual void launch()
	{
		this->thread_ = CreateThread(0, 0, &Thread::threadProc, this, 0, &this->id_);
		this->isWorking_ = true;
	}

	virtual void join()
	{
		WaitForSingleObject(this->thread_, 0);
	}

	virtual bool isWorking() const
	{
		return (this->isWorking_);
	}
};

}			// namespace LWP