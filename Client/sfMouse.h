#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "IInput.h"
#include "sfWindow.h"

class sfMouse :	public IInput
{
	sfWindow&									window_;
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

