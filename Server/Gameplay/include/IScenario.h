
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

struct Timepoint
{
public:
	float		time_;
	IEntity *	spawn_;

public:
	Timepoint(float t, IEntity* E) : time_(t), spawn_(E) {}

public:
	bool	isValid() const { return (this->time_ >= 0.0f && this->spawn_); }
};


class IScenario
{
public:
	virtual  ~IScenario(void) {}

public:
	virtual bool		isOver() const				= 0;
	virtual void		addNewEvent(Timepoint)		= 0;
	virtual IEntity *	getNextEvent(float atTime)	= 0;
};
