#pragma once

#include <SFML/Graphics.h>

class IDrawable
{
public:
  virtual ~IDrawable(void) {}
  virtual int getSkin() const = 0; // Succesptible de changer
};
