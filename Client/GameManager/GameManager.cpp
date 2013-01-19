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
			//stack_.top->treatMove(move);
			return ;
	}
	Command<Death> * death = dynamic_cast<Command<Death> *>(action);

	if (death)
	{
			//stack_.top->treatDeath(death);
			return ;
	}
	Command<Fire> * fire = dynamic_cast<Command<Fire> *>(action);

	if (fire)
	{
		//stack_.top->treatFire(fire);
		return ;
	}
	Command<NewEntity> * newentity = dynamic_cast<Command<NewEntity> *>(action);

	//if (newentity)
		//stack_.top->treatNewEntity(newentity);
}

ICommand*	GameManager::getAction()
{
	return net_->getAction();
}