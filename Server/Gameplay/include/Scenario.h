#ifndef SCENARIO_HPP
#define SCENARIO_HPP

#include <iostream>
#include <deque>
#include "IEntity.h"

struct Timepoint {
  float time_;
  IEntity * spawn_;
};

class Scenario {
  std::deque<Timepoint> timeline_;
  float duration_;
public:
  Scenario(float);
  ~Scenario();
  IEntity * getNextEvent(float);
  void addNewEvent(Timepoint);
  bool isOver(float);
};

#endif
