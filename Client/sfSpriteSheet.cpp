#include "sfSpriteSheet.h"

sfSpriteSheet::sfSpriteSheet(std::string const& path, int nbAnim, int nbFrame) : window_(sfmlWin), nbAnim_(nbAnim), nbFrame_(nbFrame), currentFrame_(-1)
{
	if (!texture_.loadFromFile(path))
		throw ("Exception TODO");
	anim_.setTexture(texture_);
	size_ = texture_.getSize();
	sub_.top = 0;
	sub_.left = 0;
	sub_.width = size_.x / nbFrame;
	sub_.height = size_.y / nbAnim;
	anim_.setTextureRect(sub_);
}


sfSpriteSheet::~sfSpriteSheet(void)
{
}

void	sfSpriteSheet::draw()
{
	window_.draw(anim_);
}

void	sfSpriteSheet::playAnimation()
{
	++currentFrame_;
	if (currentFrame_ == nbFrame_)
		currentFrame_ = 0;
	sub_.left = currentFrame_ * size_.x / nbFrame_;
	anim_.setTextureRect(sub_);
}

sf::Sprite const&	sfSpriteSheet::getSprite()
{
	return anim_;
}
