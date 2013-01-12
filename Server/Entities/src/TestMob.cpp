#include "TestMob.h"

TestMob::TestMob(int life, int power, int skin, HitBox hb, Point pos)
  : life_(life), power_(power), skin_(skin), hb_(hb), pos_(pos)
{
}

TestMob::~TestMob() {
}

int TestMob::getPower() const {
  return this->power_;
}

const HitBox & TestMob::getHitBox() const {
  return this->hb_;
}

void TestMob::destroy() {
  std::cout << "Boom !!1 LOL" << std::endl;
}

void TestMob::subLife(int minus) {
  this->life_ -= minus;
  if (this->life_ < 0)
    this->destroy();
}

int TestMob::getSkin() const {
  return this->skin_;
}

const Point & TestMob::getPos() const {
  return this->pos_;
}

const Point & TestMob::getDirection() const {
  return this->dir_;
}

float TestMob::getSpeed() const {
  return this->speed_;
}

int TestMob::getInput() const {
  std::cout << "Input !" << std::endl;
  return 1;
}

eAction TestMob::getNextAction(float atTime) const {
  for (std::deque<Actions>::const_iterator it = this->script_.begin(); it != this->script_.end(); ++it)
    if ((*it).time_ == atTime)
      return (*it).action_;
  return (ERROR);
}
