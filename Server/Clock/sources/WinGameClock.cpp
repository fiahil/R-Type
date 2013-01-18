//
// WinGameClock.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Clock/timer/src
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Fri Jan 18 16:36:21 2013 alexandre teisseire
// Last update Fri Jan 18 16:57:41 2013 alexandre teisseire
//

#include	"WinGameClock.h"

WinGameClock::WinGameClock()
{
  this->startCount.QuadPart = 0;
  QueryPerformanceFrequency(&(this->frequency));
  QueryPerformanceCounter(&startCount);
}

WinGameClock::~WinGameClock() {}

void		WinGameClock::reset()
{
  QueryPerformanceCounter(&startCount); 
}

float		WinGameClock::getElapsedTime()
{
  LARGE_INTEGER	save;
  float		elapsedTime;

  QueryPerformanceCounter(&save);

  elapsedTime = (this->startCount).QuadPart * (1000000.0f / (this->frequency).QuadPart);
  elapsedTime -= save.QuadPart * (1000000.0f / (this->frequency).QuadPart);

  return (elapsedTime * 0.001f);
}
