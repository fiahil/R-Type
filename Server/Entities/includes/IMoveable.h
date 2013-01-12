#pragma once

#include "IEntity.h"

class IMoveable
{
public:
  virtual ~IMoveable(void) {}
  virtual const Point & getDirection() const = 0;
  virtual float getSpeed() const = 0; // Les deux retour a p-e revoir.
};
