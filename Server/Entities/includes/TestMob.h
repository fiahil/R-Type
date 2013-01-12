#pragma once

#include <iostream>
#include "IEntity.h"
#include "IArmable.h"
#include "ICollidable.h"
#include "IDestroyable.h"
#include "IDrawable.h"
#include "IMoveable.h"
#include "IPlayable.h"
#include "IScriptable.h"

class TestMob
  : public IEntity,
    public IArmable,
    public ICollidable,
    public IDestroyable,
    public IDrawable,
    public IMoveable,
    public IPlayable,
    public IScriptable
{
  int life_;
  int power_;
  int skin_;
  float speed_;
  Point dir_;
  HitBox hb_;
  Point pos_;
  std::deque<Actions> script_;
public:
  TestMob(int, int, int, HitBox, Point);
  ~TestMob();
  int getPower() const;
  const HitBox & getHitBox() const;
  void destroy();
  void subLife(int);
  int getSkin() const;
  const Point & getPos() const;
  const Point & getDirection() const;
  float getSpeed() const;
  int getInput() const;
  eAction getNextAction(float) const;
};
