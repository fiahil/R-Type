#include "Alien1.h"

Alien1::Alien1(const Point& pos, const Point& dir)
  : AMonster(pos, dir)
{
  this->life_ = 100;
  this->power_ = 10;
  this->skin_ = Alien_1;
  this->speed_ = 0.5f;

  // Build HitBox here : Cf sprite.
  // Build script here
}

Alien1::~Alien1()
{
}
