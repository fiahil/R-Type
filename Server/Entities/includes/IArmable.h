#pragma once

class IArmable
{
public:
  virtual ~IArmable(void) {}
  virtual int getPower() const = 0;
};
