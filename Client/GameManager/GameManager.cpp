#include <iostream>
#include "GameManager.h"
#include "NetworkManager.hpp"
#include "sfWindow.h"
#include "sfJoystick.h"
#include "sfKeyboard.h"
#include "sfMouse.h"
#include "SFML/System.hpp"
#include "SFML/System/Clock.hpp"

extern sfWindow sfmlWin;
GameManager*	GameManager::GM = 0;

GameManager::GameManager(char** av) : alive(true)
{ 
  this->net_ = new NetworkManager(av);
  this->input_ = new sfKeyboard();
}


GameManager::~GameManager(void)
{
}

void		GameManager::treatAction(ICommand *action)
{
  if (!action)
    return ;

  Command<Move> * move = dynamic_cast<Command<Move> *>(action);

  if (move)
    {
      stack_.top()->treatMove(move);
      return ;
    }
  Command<Death> * death = dynamic_cast<Command<Death> *>(action);

  if (death)
    {
      stack_.top()->treatDeath(death);
      return ;
    }
  Command<Fire> * fire = dynamic_cast<Command<Fire> *>(action);

  if (fire)
    {
      stack_.top()->treatShoot(fire);
      return ;
    }
  Command<NewEntity> * newentity = dynamic_cast<Command<NewEntity> *>(action);

  if (newentity)
    stack_.top()->treatNewEntity(newentity);
}

ICommand*	GameManager::getAction()
{
	return net_->getAction();
}

bool		GameManager::isAlive() const
{
  return this->alive;
}

void		GameManager::pushStage(Stage*S)
{
  this->stack_.push(S);
}

void		GameManager::update()
{
   if (!this->stack_.empty() && this->alive)
    {
      this->stack_.top()->update();
    }
}

void		GameManager::draw()
{
  if (!this->stack_.empty() && this->alive)
    {
      this->stack_.top()->draw();
    }
}

void		GameManager::release()
{
}

void		GameManager::run()
{
  sf::Clock	Clock;
  float		ElapsedTime = 0;

  while (this->alive)
    {
      if (Clock.getElapsedTime().asSeconds() > 0.150f)
	{
	  Clock.restart(); 
	  ElapsedTime = 0;
	  this->update();
	  this->draw();
	  this->net_->run();
	}
    }
}
