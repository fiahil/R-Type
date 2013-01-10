
#pragma once

#include	<Windows.h>

#include	"ICondVar.h"

namespace LWP
{

class CondVar : public ICondVar
{
private:
	CONDITION_VARIABLE cv_;
	CRITICAL_SECTION cs_;

public:
	CondVar(void);
	virtual ~CondVar(void);
	virtual void	wait(void);
	virtual void	notify(void);
	virtual void	broadcast(void);
};

}		// namespace LWP
