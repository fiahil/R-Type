#pragma once

#include "IEntity.h"

enum eAction {
  SPEEDUP,
  SPEEDOWN,
  VIEWVERT,
  VIEWHORI,
  FIRE,
  ERRORACTION
};

struct Actions {
  float time_;
  eAction action_;
};

class IScriptable
{
public:
  virtual ~IScriptable(void) {}
  virtual eAction getNextAction(float) const = 0;
};
