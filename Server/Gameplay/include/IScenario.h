
#pragma once

#include <iostream>
#include <deque>
#include "IEntity.h"

struct Timepoint {
  float time_;
  IEntity * spawn_;
};

class IScenario {
public:
  virtual  ~IScenario(void) {}
  virtual IEntity * getNextEvent(float) = 0;
  virtual void addNewEvent(Timepoint) = 0;
  virtual bool isOver(float) = 0;
};
