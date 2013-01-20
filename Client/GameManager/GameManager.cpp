#include <iostream>
#include "GameManager.h"
#include "NetworkManager.hpp"
#include "sfWindow.h"
#include "sfJoystick.h"
#include "sfKeyboard.h"
#include "sfMouse.h"
#include "SFML/System.hpp"
#include "SFML/System/Clock.hpp"
#include <SFML/Graphics.hpp>
#include "sfJoystick.h"
#include "sfMouse.h"
#include "sfKeyboard.h"
#include "sfSpriteSheet.h"
#include "GameComponent.h"
#include "Stage.h"
#include "Skin.h"

#ifdef WIN32
#include <boost\asio.hpp>
#include <Windows.h>
#endif

extern	std::vector<skin>	skinArray;
extern	sfWindow	sfmlWin;


GameManager*	GameManager::GM = 0;

GameManager::GameManager(char** av) : alive(true)
{ 
  fillArray();
  test2 = new sfSpriteSheet(skinArray[8].filePath, skinArray[8].anim, skinArray[8].frame);
  ships = new sfSpriteSheet("../Resources/Sprite/boss.gif", 1, 9);
  boom = new sfSpriteSheet(skinArray[7].filePath, skinArray[7].anim, skinArray[7].frame);
  boom2 = new sfSpriteSheet("../Resources/Sprite/boss_death.gif", 1, 9);

  this->input3 = new sfKeyboard();
  vaisseau2 = new GameComponent(test2, boom);
  this->net_ = new NetworkManager(av);
  
  input3->autoBind(UpKey, sf::Keyboard::W);
  input3->autoBind(DownKey, sf::Keyboard::S);
  input3->autoBind(LeftKey, sf::Keyboard::A);
  input3->autoBind(RightKey, sf::Keyboard::D);
  input3->autoBind(FireKey, sf::Keyboard::Space);
  
  Stage* st = new Stage();
  st->add(vaisseau2);
  this->stack_.push(st);
  
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
  sf::Event ev;
  int x = 0, y = 0;
  sfmlWin.pollEvent(ev);
  if (ev.type == sf::Event::Closed)
    sfmlWin.getWindow().close();
 
  vaisseau2->move(input3->getLastInput(UpKey), input3->getLastInput(LeftKey));

  if (input3->getLastInput(UpKey))
    y = -4;
    else if (input3->getLastInput(DownKey))
    y = 4;
    if (input3->getLastInput(LeftKey))
    x = -4;
    else if (input3->getLastInput(RightKey))
    x = 4;
    vaisseau2->move(x, y);

  if (input3->isPressed(FireKey))
    vaisseau2->death();
		
  this->stack_.top()->update();
  sfmlWin.clear();
  this->stack_.top()->draw();
  sfmlWin.display();
  {
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
      if (Clock.getElapsedTime().asSeconds() > 0.100f)
	{
	  Clock.restart(); 
	  ElapsedTime = 0;
	  this->update();
	  this->draw();
	  this->net_->run();
	}
    }
}
