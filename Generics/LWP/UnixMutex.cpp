
#include	"UnixMutex.h"

namespace	LWP
{

Mutex::Mutex(void)
{
  pthread_mutex_init(&this->m_, 0);
}

Mutex::~Mutex(void)
{
}

void Mutex::lock(void)
{
  pthread_mutex_lock(&this->m_);
}

void Mutex::unlock(void)
{
  pthread_mutex_unlock(&this->m_);
}

bool Mutex::trylock(void)
{
  return (pthread_mutex_trylock(&this->m_) ? true : false);
}

}		// namespace LWP
