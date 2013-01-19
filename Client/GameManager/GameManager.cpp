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
			stack_.top->treatMove(move);
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
/*
void	Stage::treatMove(Command<Move> *cmd)
{
	struct Move deplace = cmd->getT();
	this->components.at(deplace.id).move(deplace.x, deplace.y);
}

void	Stage::treatDeath(Command<Death> *cmd)
{
	struct Death dead = cmd->getT();
	this->components.at(dead.id).death();
}

void	Stage::treatDeath(Command<Fire> *cmd)
{
	struct Fire shoot = cmd->getT();
	this->components.at(shoot.id).fire(shoot.x, shoot.y);
}
#include	"GameComponent.h"
void	Stage::treatNewEntity(Command<NewEntity> *cmd)
{
	struct NewEntity life = cmd->getT();
	ISpriteSheet *sprite = new sfSpriteSheet(life.filename, life.anim, life.frame);
	ISpriteSheet *death = new sfSpriteSheet("..\\Resources\\Sprite\\little_death.gif", 1, 6);
	this->components.at(life.id) = new GameComponent(sprite, death);
}
*/