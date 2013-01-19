#pragma once

#include	<deque>
#include	"IInput.h"
#include	"IGameWindow.h"
#include	"INetworkManager.hpp"
#include	"Command.h"
#include	"Stage.h"

class GameManager : public IGameManager
{
  IGameWindow	*window_;
  IInput	*input_;
  INetworkManager *net_;
  std::deque<Stage*> stack_;

public:
  GameManager(void);
  virtual ~GameManager(void);

public:
  void		treatAction(ICommand *);
  ICommand*	getAction();

public:
  virtual void	run();
  virtual void	update();
  virtual void	draw();
  virtual void	release();
};

