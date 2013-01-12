#pragma once

class IPlayable
{
public:
  virtual ~IPlayable(void) {}
  virtual int getInput() const = 0; // Changement de retour plus que probable.
};
