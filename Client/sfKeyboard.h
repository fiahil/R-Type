
#pragma	once

#include <SFML/Graphics.hpp>
#include <map>
#include "IInput.h"
#include "sfWindow.h"

class sfKeyboard : public IInput
{
	sfWindow&									window_;
	std::map<GameInputKey, sf::Keyboard::Key>	binding_;
	sf::Event									event_;

public:
	sfKeyboard();
	~sfKeyboard();
	void	Bind(GameInputKey);
	int		getLastInput(GameInputKey);
	bool	isPressed(GameInputKey);
};
