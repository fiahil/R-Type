#include "GameManager.h"


GameManager::GameManager(void)
{
}


GameManager::~GameManager(void)
{
}

void	GameManager::treatAction(ICommand *action)
{
	if (!action)
		return ;

	Command<Move> * move = dynamic_cast<Command<Move> *>(action);

	if (move)
	{
			stack_.front()->treatMove(move);
			return ;
	}
	Command<Death> * death = dynamic_cast<Command<Death> *>(action);

	if (death)
	{
			stack_.front()->treatDeath(death);
			return ;
	}
	Command<Fire> * fire = dynamic_cast<Command<Fire> *>(action);

	if (fire)
	{
		stack_.front()->treatFire(fire);
		return ;
	}
	Command<NewEntity> * newentity = dynamic_cast<Command<NewEntity> *>(action);

	if (newentity)
		stack_.front()->treatNewEntity(newentity);
}

ICommand*	GameManager::getAction()
{
	return net_->getAction();
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
  //	Timer
  //	while(isAlive)
  //	{
  //	  Timer.wait();
  this->update();
  this->draw();
  //    }
}
