//
// GameClock.hpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Clock
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Fri Jan 18 14:41:06 2013 alexandre teisseire
// Last update Fri Jan 18 15:13:07 2013 alexandre teisseire
//

#ifndef	__GAMECLOCK_HPP__
#define	__GAMECLOCK_HPP__

#include	<time.h>
#include	<sys/time.h>
#include	"IClock.hpp"

class		GameClock : public IClock
{
private:
  struct timeval	_startMark;
  struct timeval	_saveMark;

public:
  GameClock();
  ~GameClock();

public:
  virtual void	update();
  virtual float	getElapsedTime() const;
};

#endif
