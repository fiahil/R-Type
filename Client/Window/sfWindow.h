#pragma once

#include <SFML/Graphics.hpp>
#include "IGameWindow.h"

class sfWindow : public IGameWindow
{
	sf::RenderWindow window_;
 
public:
	void	getWindowSize(int&, int&);
	void	gainFocus() {};
	void	lostFocus() {};
	void	setTitle(std::string const&);
	void	setCursorVisible(bool);
	void	pollEvent(sf::Event&);
	void	draw(sf::Drawable const& drawable);
	bool	isOpen();
	void	clear();
	void	display();
	sf::Window&	getWindow();

	sfWindow(int x = 800, int y = 600);
	~sfWindow();
};

extern	sfWindow sfmlWin;