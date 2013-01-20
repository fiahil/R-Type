#pragma once

#include "IScenario.h"

class Scenario : public IScenario
{
private:
	std::deque<Timepoint> timeline_;

public:
  Scenario();
  virtual ~Scenario();

public:
	virtual bool		isOver() const;
	virtual void		addNewEvent(Timepoint);
	virtual IEntity *	getNextEvent(float atTime);
};