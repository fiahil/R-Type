#include "Stage.h"
#include "IGameComponent.h"

Stage::Stage(void)
{
}


Stage::~Stage(void)
{
}

void	Stage::treatMove(Command<Move> *cmd)
{
	struct Move move = cmd->getT();
	this->deck_.at(move.id)->move(move.x, move.y);
}

void	Stage::treatDeath(Command<Death> *cmd)
{
	struct Death death = cmd->getT();
	this->deck_.at(death.id)->death();
}

void	Stage::treatShoot(Command<Fire> *cmd)
{
	struct Fire fire = cmd->getT();
	IGameComponent * bullet = GameResources::shoot(fire.x, fire.y);
	this->deck_.at(fire.id) = dynamic_cast<GameComponent*>(bullet);
}

void	Stage::treatNewEntity(Command<NewEntity> *cmd)
{
	struct NewEntity entity = cmd->getT();
	ISpriteSheet	*sprite = new sfSpriteSheet(entity.filename, entity.anim, entity.frame);
	ISpriteSheet	*death = new sfSpriteSheet("..\\Resources\\Sprite\\little_death.gif", 1, 6);
	GameComponent	*component = new GameComponent(sprite, death);
	this->deck_.at(entity.id) = component;
	this->deck_.at(entity.id)->move(entity.x_start, entity.y_start);
}

void	Stage::update()
{
	std::deque<GameComponent*>::iterator it = deck_.begin();

	for (; it != deck_.end();)
	{
		(*it)->update();
		if ((*it)->getEndLife())
		{
			delete *it;
			it = deck_.erase(it);
		}
		else
			++it;
	}
}

void	Stage::draw()
{
	std::deque<GameComponent*>::iterator it = deck_.begin();

	for (; it != deck_.end(); ++it)
	{
		(*it)->draw();
	}
}

void	Stage::add(GameComponent*lol)
{
	deck_.push_back(lol);
}