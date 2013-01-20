#pragma once

#include	<stack>
#include	"IGameManager.hpp"
#include	"IInput.h"
#include	"IGameWindow.h"
#include	"INetworkManager.hpp"
#include	"Command.h"
#include	"Stage.h"
#include "sfJoystick.h"
#include "sfMouse.h"
#include "sfKeyboard.h"
#include "sfSpriteSheet.h"
#include "GameComponent.h"
#include "Skin.h"

class GameManager : public IGameManager
{
  bool		alive;
  IInput	*input_;
  INetworkManager *net_;
  std::stack<Stage*> stack_;
  int		RoomId;
  
  ISpriteSheet	*test2;
  ISpriteSheet	*ships;
  ISpriteSheet	*boom;
  ISpriteSheet	*boom2;
  IInput	*input3;
  GameComponent	*vaisseau2;


public:
  GameManager(char**);
  virtual ~GameManager(void);

public:
  static GameManager *GM;
  void		treatAction(ICommand *);
  ICommand*	getAction();
  bool		isAlive() const;
  void		pushStage(Stage*);

public:
  virtual void	run();
  virtual void	update();
  virtual void	draw();
  virtual void	release();
};
