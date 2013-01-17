#include "Alien1.h"

#include <iostream> //remove

Alien1::Alien1(const Point& pos, const Point& dir)
  : AMonster(pos, dir)
{
  this->life_ = 100;
  this->power_ = 100;
  this->skin_ = Alien_1;
  this->speed_ = 0.5f;

  // Build HitBox here : Cf sprite.
  // Build script here

  std::cout << "-- Construction Alien1" << std::endl;
}

Alien1::~Alien1()
{
  std::cout << "-- Destruction Alien1" << std::endl;
}
