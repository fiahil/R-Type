#include "Stage.h"
#include "Skin.h"
#include "IGameComponent.h"

extern	std::vector<skin> skinArray;

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
	ISpriteSheet	*sprite = new sfSpriteSheet(skinArray[entity.idSkin].filePath, skinArray[entity.idSkin].anim, skinArray[entity.idSkin].frame);
	ISpriteSheet	*death = new sfSpriteSheet(skinArray[3].filePath, skinArray[3].anim, skinArray[3].frame);
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
			it = deck_.erase(it);
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