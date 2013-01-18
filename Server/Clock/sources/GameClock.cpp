//
// GameClock.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Clock
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Fri Jan 18 14:46:53 2013 alexandre teisseire
// Last update Fri Jan 18 15:32:12 2013 alexandre teisseire
//

#include	"GameClock.hpp"

GameClock::GameClock()
{
  gettimeofday(&(this->_startMark), NULL);
}

GameClock::~GameClock() {}

void		GameClock::reset()
{
  gettimeofday(&(this->_startMark), NULL);
}

float		GameClock::getElapsedTime() const
{
  float	elapsedTime;
  struct timeval saveMark;

  gettimeofday(&saveMark, NULL);

  elapsedTime = (saveMark.tv_usec - this->_startMark.tv_usec) / 1000000.0f;
  elapsedTime += (saveMark.tv_sec - this->_startMark.tv_sec);

  return (elapsedTime);
}
