/*
** WinGameClock.h for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Clock/timer/src
** 
** Made by alexandre teisseire
** Login   <teisse_a@epitech.net>
** 
** Started on  Fri Jan 18 15:55:44 2013 alexandre teisseire
** Last update Fri Jan 18 16:58:58 2013 alexandre teisseire
*/

#ifndef	_WINGAMECLOCK_H_
#define	_WINGAMECLOCK_H_

#ifdef	WIN32
#include <windows.h>
#include "IClock.h"

class	GameClock : public IClock
{
private:
  LARGE_INTEGER frequency;
  LARGE_INTEGER startCount;

public:
  GameClock();
  ~GameClock();

public:
  virtual void  reset();
  virtual float getElapsedTime() const;
};

#endif
#endif
