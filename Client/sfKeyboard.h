
#pragma	once

#include <SFML/Graphics.hpp>
#include <map>
#include "IInput.h"

typedef	int Window;

class sfKeyboard : public IInput
{
	sf::Window									window_;
	std::map<GameInputKey, sf::Keyboard::Key>	binding_;
	sf::Event									event_;

public:
	sfKeyboard();
	~sfKeyboard();
	void	Bind(GameInputKey);
	int		getLastInput(GameInputKey);
	bool	isPressed(GameInputKey);
};
