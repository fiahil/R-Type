
#pragma once

#include <iostream>
#include <deque>
#include "IEntity.h"
#include "IArmable.h"
#include "ICollidable.h"
#include "IDestroyable.h"
#include "IDrawable.h"
#include "IMoveable.h"
#include "IPlayable.h"
#include "IScriptable.h"

struct Timepoint {
  float time_;
  IEntity * spawn_;
};

class IScenario {
public:
  virtual  ~IScenario(void) {}
  virtual IEntity * getNextEvent(float,int) = 0;
  virtual void addNewEvent(Timepoint) = 0;
  virtual bool isOver(float) = 0;
};
