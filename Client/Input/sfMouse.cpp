
#include "sfMouse.h"

sfMouse::sfMouse(void) : window_(sfmlWin)
{
	sf::Vector2i vec2(0, 0);
	sf::Mouse::setPosition(vec2, sfmlWin.getWindow());
	sf::Vector2i vec = sf::Mouse::getPosition(sfmlWin.getWindow());
	lastPos_.insert(std::pair<GameInputKey, int>(UpKey, vec.y));
	lastPos_.insert(std::pair<GameInputKey, int>(DownKey, vec.y));
	lastPos_.insert(std::pair<GameInputKey, int>(RightKey, vec.x));
	lastPos_.insert(std::pair<GameInputKey, int>(LeftKey, vec.x));
	sfmlWin.getWindow().setMouseCursorVisible(false);
}

sfMouse::~sfMouse(void)
{
	sfmlWin.getWindow().setMouseCursorVisible(true);
}

void	sfMouse::Bind(GameInputKey key)
{
	window_.pollEvent(event_);
	if (event_.type == sf::Event::MouseButtonPressed)
		binding_.insert(std::pair<GameInputKey, sf::Mouse::Button>(key, event_.mouseButton.button));
}

int		sfMouse::getLastInput(GameInputKey key)
{
	if (key == FireKey || key == UltimateKey)
		return 100;

	sf::Vector2i pos = sf::Mouse::getPosition(sfmlWin.getWindow());
	int delta = lastPos_[key];

	if (key == UpKey || key == DownKey)
	{
		lastPos_[UpKey] = delta - pos.x;
		lastPos_[DownKey] = pos.x - delta;
	}
	else if (key == RightKey || key == LeftKey)
	{
		lastPos_[RightKey] = pos.y - delta;
		lastPos_[LeftKey] = delta - pos.y;
	}
	sf::Mouse::setPosition(pos, sfmlWin.getWindow());
	return (delta - lastPos_[key]) >> 4;
}

bool	sfMouse::isPressed(GameInputKey key)
{
	return sf::Mouse::isButtonPressed(binding_[key]);
}

void sfMouse::autoBind(GameInputKey, int)
{
}
