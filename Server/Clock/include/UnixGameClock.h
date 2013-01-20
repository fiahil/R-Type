/*
** UnixGameClock.h for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Clock/timer/src
** 
** Made by alexandre teisseire
** Login   <teisse_a@epitech.net>
** 
** Started on  Fri Jan 18 16:00:13 2013 alexandre teisseire
** Last update Fri Jan 18 16:59:37 2013 alexandre teisseire
*/

#ifndef _UNIXGAMECLOCK_H_
#define _UNIXGAMECLOCK_H_

#include	<time.h>
#include	<sys/time.h>
#include	"IClock.h"

class	GameClock : public IClock
{
 private:
  struct timeval _startMark;
  
 public:
  GameClock();
  virtual ~GameClock();
  
  virtual void	reset();
  virtual float getElapsedTime() const;
};

#endif
