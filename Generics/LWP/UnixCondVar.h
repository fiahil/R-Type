
#pragma once

#include	<pthread.h>

#include	"ICondVar.h"

namespace	LWP
{

class		CondVar : public ICondVar
{
private:
  pthread_cond_t c_;
  pthread_mutex_t m_;

public:
  CondVar(void);
  ~CondVar(void);
  void wait(void);
  void notify(void);
  void broadcast(void);
};

}		// namespace LWP
