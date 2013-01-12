#pragma once

#include "IEntity.h"

enum eAction {
  SPEEDUP,
  SPEEDOWN,
  VIEWVERT,
  VIEWHORI,
  ERROR
};

typedef struct s_Actions {
  float time_;
  eAction action_;
} Actions;

class IScriptable
{
public:
  virtual ~IScriptable(void) {}
  virtual eAction getNextAction(float) const = 0;
};
