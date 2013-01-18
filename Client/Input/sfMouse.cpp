
#include "sfMouse.h"

sfMouse::sfMouse(void) : window_(sfmlWin)
{
	lastPos_.insert(std::pair<GameInputKey, int>(UpKey, 0));
	lastPos_.insert(std::pair<GameInputKey, int>(DownKey, 0));
	lastPos_.insert(std::pair<GameInputKey, int>(RightKey, 0));
	lastPos_.insert(std::pair<GameInputKey, int>(LeftKey, 0));
}


sfMouse::~sfMouse(void)
{
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

	sf::Vector2i pos = sf::Mouse::getPosition();
	int delta = 0;

	if (key == UpKey || key == DownKey)
	{
		delta = lastPos_[key] - pos.y;
		lastPos_[LeftKey] = pos.y;
		lastPos_[DownKey] = pos.y;
	}
	else if (key == RightKey || key == LeftKey)
	{
		delta = lastPos_[key] - pos.x;
		lastPos_[RightKey] = pos.x;
		lastPos_[LeftKey] = pos.x;
	}
	
	delta = (delta < 0 ? -delta : delta);
	delta = (delta > 100 ? 100 : delta);
	
	return delta;
}

bool	sfMouse::isPressed(GameInputKey key)
{
	return sf::Mouse::isButtonPressed(binding_[key]);
}