

#include "sfJoystick.h"

#include <iostream>


sfJoystick::sfJoystick() : window_(sfmlWin)
{
	for (joystickNb_ = 0; joystickNb_ < 5; joystickNb_++)
		{
			if (sf::Joystick::isConnected(joystickNb_))
				break;
		}

	if (joystickNb_ == 5)
		throw ("Exception todo");

	maxButton_ = sf::Joystick::getButtonCount(joystickNb_);
	sf::Joystick::update();
	x_ = sf::Joystick::Axis::X;
	y_ = sf::Joystick::Axis::Y;
}


sfJoystick::~sfJoystick(void)
{
}

void	sfJoystick::Bind(GameInputKey key)
{
	window_.pollEvent(event_);
	if (event_.type == sf::Event::JoystickButtonPressed)
		binding_.insert(std::pair<GameInputKey, int>(key, event_.joystickButton.button));
}

int		sfJoystick::getLastInput(GameInputKey key)
{
	sf::Joystick::update();
	if (key == DownKey || key == UpKey)
		{
			const double tmp = sf::Joystick::getAxisPosition(joystickNb_, x_) / 7.5;
		
			return static_cast<int>(tmp);
		}
	else if (key == LeftKey || key == RightKey)
		{
			const double tmp = sf::Joystick::getAxisPosition(joystickNb_, y_) / 7.5;
		
			return static_cast<int>(tmp);
		}
	else
		return sf::Joystick::isButtonPressed(joystickNb_, binding_[key]) ? 100 : 0;
}

bool	sfJoystick::isPressed(GameInputKey key)
{
	sf::Joystick::update();

	return sf::Joystick::isButtonPressed(joystickNb_, binding_[key]);
}

void sfJoystick::autoBind(GameInputKey key, int button)
{
	binding_[key] = button;
}
