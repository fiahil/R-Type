#include "GameManager.h"
#include "NetworkManager.hpp"
#include "sfWindow.h"
#include "sfJoystick.h"
#include "sfKeyboard.h"
#include "sfMouse.h"
#include "SFML/System.hpp"
#include "SFML/System/Clock.hpp"

extern sfWindow sfmlWin;

GameManager::GameManager(char** av) : alive(true)
{ 
  this->net_ = new NetworkManager(av);
  this->input_ = new sfKeyboard();

  this->net_->run();
}


GameManager::~GameManager(void)
{
}

// void	GameManager::treatAction(ICommand *action)
// {
//   if (!action)
//     return ;

//   Command<Move> * move = dynamic_cast<Command<Move> *>(action);

//   if (move)
//     {
//       stack_.front()->treatMove(move);
//       return ;
//     }
//   Command<Death> * death = dynamic_cast<Command<Death> *>(action);

//   if (death)
//     {
//       stack_.front()->treatDeath(death);
//       return ;
//     }
//   Command<Fire> * fire = dynamic_cast<Command<Fire> *>(action);

//   if (fire)
//     {
//       stack_.front()->treatFire(fire);
//       return ;
//     }
//   Command<NewEntity> * newentity = dynamic_cast<Command<NewEntity> *>(action);

//   if (newentity)
//     stack_.front()->treatNewEntity(newentity);
// }

ICommand*	GameManager::getAction()
{
	return net_->getAction();
}

bool		GameManager::isAlive() const
{
  return this->alive;
}

void	GameManager::update()
{

}

void	GameManager::draw()
{

}

void	GameManager::release()
{

}

void		GameManager::run()
{
  sf::Clock	Clock;
  float		ElapsedTime = 0;

  while (this->alive)
    {
      ElapsedTime += Clock.getElapsedTime().asSeconds();
      if (ElapsedTime > 0.167f)
	{
	  Clock.restart();
	  this->update();
	  this->draw();
	}
    }
}
