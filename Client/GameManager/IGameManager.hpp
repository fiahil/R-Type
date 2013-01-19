#pragma once

class		IGameManager
{
public:
  virtual ~IGameManager() {}

public:
  virtual void	run() = 0;
  virtual void	update() = 0;
  virtual void	draw() = 0;
  virtual void	release() = 0;
};
