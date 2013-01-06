
#include	"UnixMutex.h"

namespace	LWP
{

Mutex::Mutex(void)
{
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
