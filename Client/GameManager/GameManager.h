#pragma once

#include	<stack>
#include	"IGameManager.hpp"
#include	"IInput.h"
#include	"IGameWindow.h"
#include	"INetworkManager.hpp"
#include	"Command.h"
#include	"Stage.h"

class GameManager : public IGameManager
{
  IInput	*input_;
  INetworkManager *net_;
  std::stack<Stage*> stack_;

public:
  GameManager(char**);
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

