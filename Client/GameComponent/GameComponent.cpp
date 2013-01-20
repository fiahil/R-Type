
#include "GameComponent.h"

GameComponent::GameComponent(ISpriteSheet* s, ISpriteSheet* d) : sprite_ (s), death_(d), x_(0), y_(0), endLife_(false)
{
}

GameComponent::~GameComponent(void)
{
}

void	GameComponent::draw()
{
	if (state_ == DEATH)
		death_->draw();
	else
		sprite_->draw();
}

void	GameComponent::initialize(ISpriteSheet* sprite, ISpriteSheet* death)
{
	sprite_ = sprite;
	death_ = death;
}

void	GameComponent::release()
{
}

void	GameComponent::update()
{
	sprite_->moveFrom(x_, y_);
	death_->moveFrom(x_, y_);
	if (state_ != DEATH)
		sprite_->playAnimation(0);
	else
		if (death_->playAnimation(0))
			endLife_ = true;
}

void	GameComponent::death()
{
	state_ = DEATH;
}

void	GameComponent::move(int x, int y)
{
	if (!x && !y && state_ != DEATH)
		state_ = IDLE;
	else if (state_ != DEATH)
		state_ = MOVE;
	x_ = x;
	y_ = y;
}

bool	GameComponent::getEndLife() const
{
	return endLife_;
}
