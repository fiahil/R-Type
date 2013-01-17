
#include	"WinCondVar.h"

namespace LWP
{

CondVar::CondVar(void)
{
	InitializeConditionVariable(&this->cv_);
	InitializeCriticalSection(&this->cs_);
}

CondVar::~CondVar(void)
{
	DeleteCriticalSection(&this->cs_);
}

void	CondVar::wait(void)
{
	EnterCriticalSection(&this->cs_);
	SleepConditionVariableCS(&this->cv_, &this->cs_, INFINITE);
	LeaveCriticalSection(&this->cs_);
}

void	CondVar::notify(void)
{
	WakeConditionVariable(&this->cv_);
}

void	CondVar::broadcast(void)
{
	WakeAllConditionVariable(&this->cv_);
}

}		// namespace LWP