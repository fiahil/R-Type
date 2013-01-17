#include "Scenario.h"

Scenario::Scenario(float duration) {
  if (duration < 0)
    std::cerr << "Duration can't be inferior to 0." << std::endl;
  else
    this->duration_ = duration;
  Timepoint tp1;
  tp1.time_ = 1.f;
}

Scenario::~Scenario() {

}

IEntity * Scenario::getNextEvent(float atTime) {
  for (std::deque<Timepoint>::iterator it = this->timeline_.begin(); it != this->timeline_.end(); ++it) {
    if ((*it).time_ == atTime)
      return (*it).spawn_;
  }
  std::cerr << "Couldn't find the event you're looking for." << std::endl;
  return NULL;
}

void Scenario::addNewEvent(Timepoint Giggowatt) {
  if (Giggowatt.time_ > 0 && Giggowatt.time_ < this->duration_)
    this->timeline_.push_back(Giggowatt);
}

bool Scenario::isOver(float time) {
  if (time < this->duration_)
    return false;
  return true;
}
