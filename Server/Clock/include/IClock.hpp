//
// Iclock.hpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Clock
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Fri Jan 18 14:36:10 2013 alexandre teisseire
// Last update Fri Jan 18 15:31:03 2013 alexandre teisseire
//

#ifndef	__ICLOCK_HPP__
#define	__ICLOCK_HPP__

class	IClock
{
public:
  ~IClock() {}
  virtual void	reset() = 0;
  virtual float getElapsedTime() const = 0;
};

#endif
