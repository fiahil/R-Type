#pragma once

#include	<SFML/Graphics.hpp>
#include	<string>
#include	"ISpriteSheet.h"
#include	"sfWindow.h"

extern	sfWindow	sfmlWin;

class sfSpriteSheet : public ISpriteSheet
{
	sfWindow&		window_;
	sf::Texture		texture_;
	sf::Vector2u	size_;
	sf::Sprite		anim_;
	int				nbAnim_;
	int				nbFrame_;
	int				currentFrame_;
	sf::Rect<int>	sub_;

public:
	sfSpriteSheet(std::string const& path, int nbAnim, int nbFrame);
	~sfSpriteSheet(void);
	void	playAnimation(int);
	void	draw();
	void	moveTo(int, int);
	void	moveFrom(int, int);
	sf::Sprite const&	getSprite();
};

