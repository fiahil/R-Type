

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "IInput.h"

class sfMouse :	public IInput
{
	sf::Window									window_;
	std::map<GameInputKey, sf::Mouse::Button>	binding_;
	sf::Event									event_;
	std::map<GameInputKey, int>					lastPos_;

public:
	sfMouse();
	~sfMouse();
	void Bind(GameInputKey);
	int getLastInput(GameInputKey);
	bool isPressed(GameInputKey);
};

