//
// UnixGameClock.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Clock/timer/src
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Fri Jan 18 16:19:04 2013 alexandre teisseire
// Last update Fri Jan 18 16:50:17 2013 alexandre teisseire
//

#include "UnixGameClock.h"

UnixGameClock::UnixGameClock()
{
  gettimeofday(&(this->_startMark), NULL);
}

UnixGameClock::~UnixGameClock() {}

void		UnixGameClock::reset()
{
  gettimeofday(&(this->_startMark), NULL);
}

float		UnixGameClock::getElapsedTime()
{
  float	elapsedTime;
  struct timeval saveMark;

  gettimeofday(&saveMark, NULL);

  elapsedTime = (saveMark.tv_usec - this->_startMark.tv_usec) / 1000000.0f;
  elapsedTime += (saveMark.tv_sec - this->_startMark.tv_sec);

  return (elapsedTime * 0.001f);
}
