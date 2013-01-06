
#include	"UnixCondVar.h"

namespace	LWP
{

CondVar::CondVar(void)
{
  pthread_cond_init(&this->c_, 0);
}

CondVar::~CondVar(void)
{
}

void CondVar::wait(void)
{
  pthread_cond_wait(&this->c_, &this->m_);
}

void CondVar::signal(void)
{
  pthread_cond_signal(&this->c_);
}

void CondVar::broadcast(void)
{
  pthread_cond_broadcast(&this->c_);
}

}
