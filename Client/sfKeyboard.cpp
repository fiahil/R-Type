
#include "sfKeyboard.h"

sfKeyboard::sfKeyboard() : window_(sfmlWin)
{
}

sfKeyboard::~sfKeyboard()
{
}

void	sfKeyboard::Bind(GameInputKey key)
{
	window_.pollEvent(event_);
	if (event_.type == sf::Event::KeyPressed)
		binding_.insert(std::pair<GameInputKey, sf::Keyboard::Key>(key, event_.key.code));
}

int		sfKeyboard::getLastInput(GameInputKey key)
{
	if (sf::Keyboard::isKeyPressed(binding_[key]))
		return 100;
	return 0;
}

bool	sfKeyboard::isPressed(GameInputKey key)
{
	return sf::Keyboard::isKeyPressed(binding_[key]);
}