#pragma once

#include "IEntity.h"

typedef struct s_HitBox {
  int xmin_;
  int xmax_;
  int ymin_;
  int ymax_;
} HitBox;

class ICollidable
{
public:
  virtual ~ICollidable(void) {}
  virtual const HitBox & getHitBox() const = 0; // Type de retour incertain ...
};
