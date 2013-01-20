/*
** IClock.h for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Clock/timer/src
** 
** Made by alexandre teisseire
** Login   <teisse_a@epitech.net>
** 
** Started on  Fri Jan 18 15:49:57 2013 alexandre teisseire
** Last update Fri Jan 18 16:22:32 2013 alexandre teisseire
*/

#ifndef _CLOCK_H_
#define _CLOCK_H_

class	IClock
{
public:
  virtual ~IClock() {}
  virtual void	reset() = 0;
  virtual float getElapsedTime() const = 0;
};

#endif
