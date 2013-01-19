#pragma once

class		IGameManager
{
public:
  virtual ~IGameManager();
  virtual void	run() = 0;

public:
  virtual void	update() = 0;
  virtual void	draw() = 0;
  virtual void	release() = 0;
};
