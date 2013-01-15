#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "IInput.h"
#include "sfWindow.h"

class sfJoystick :
	public IInput
{
	sfWindow&					window_;
	std::map<GameInputKey, int>	binding_;
	sf::Event					event_;
	unsigned int				maxButton_;
	unsigned int				joystickNb_;
	sf::Joystick::Axis			x_;
	sf::Joystick::Axis			y_;

public:
	sfJoystick();
	~sfJoystick(void);
	void Bind(GameInputKey);
	int getLastInput(GameInputKey);
	bool isPressed(GameInputKey);
};

