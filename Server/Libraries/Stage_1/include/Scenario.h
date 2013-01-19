#ifndef SCENARIO_H
#define SCENARIO_H

#include "IScenario.h"

class Scenario : public IScenario {
  std::deque<Timepoint> timeline_;
  float duration_;
public:
  Scenario(float);
  ~Scenario();
  IEntity * getNextEvent(float,int);
  void addNewEvent(Timepoint);
  bool isOver(float);
};

#endif // SCENARIO_H
