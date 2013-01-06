
#include	"UnixCondVar.h"

namespace	LWP
{

CondVar::CondVar(void)
{
  pthread_cond_init(&this->c_, 0);
  pthread_mutex_init(&this->m_, 0);
}

CondVar::~CondVar(void)
{
}

void CondVar::wait(void)
{
  pthread_mutex_lock(&this->m_);
  pthread_cond_wait(&this->c_, &this->m_);
  pthread_mutex_unlock(&this->m_);
}

void CondVar::notify(void)
{
  pthread_cond_signal(&this->c_);
}

void CondVar::broadcast(void)
{
  pthread_cond_broadcast(&this->c_);
}

}
