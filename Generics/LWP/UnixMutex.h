
#pragma once

#include	<pthread.h>

#include	"IMutex.h"

namespace	LWP
{

class		Mutex : public IMutex
{
private:
  pthread_mutex_t m_;

public:
  Mutex(void);
  ~Mutex(void);
  void lock(void);
  void unlock(void);
  bool trylock(void);
};

}		// namespace LWP
