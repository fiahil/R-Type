
#pragma once

#include	<pthread.h>

#include	"IThread.h"

namespace	LWP
{

template<typename T> class Thread : public IThread
{
private:
  pthread_t t_;
  int id_;
  bool isWorking_;
  T function_;

  Thread(void);
  static void *threadProc(void* t)
  {
    reinterpret_cast<Thread<T>*>(t)->function_();
    return (0);
  }

public:
  Thread(T function) : function_(function)
  {
    this->isWorking_ = false;
  }

  virtual ~Thread(void)
  {
  }

  virtual bool isWorking(void) const
  {
    return (this->isWorking_);
  }

  virtual void launch(void)
  {
    this->_id = pthread_create(&this->_thread, 0, &Thread::threadProc, 0);
  }

  virtual void join(void)
  {
    pthread_join(this->_thread, 0);
  }
};

}		// namespace LWP
