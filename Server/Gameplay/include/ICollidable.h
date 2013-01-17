#pragma once

#include "IEntity.h"

struct HitBox
{
  int xmin_;
  int xmax_;
  int ymin_;
  int ymax_;

  HitBox(int x1, int y1, int width, int heigh)
    :	xmin_(x1), ymin_(y1), xmax_(x1 + width), ymax_(y1 + heigh) {}
};

class ICollidable
{
public:
  virtual ~ICollidable(void) {}
  virtual const HitBox & getHitBox() const = 0; // Type de retour incertain ...
};
