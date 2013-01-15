#include "sfWindow.h"

sfWindow	sfmlWin;

void	sfWindow::setTitle(std::string const& title)
{
	window_.setTitle(title);
}

void	sfWindow::getWindowSize(int& x, int& y)
{
	sf::Vector2i	pos = window_.getPosition();

	x = pos.x;
	y = pos.y;
}

void	sfWindow::setCursorVisible(bool on)
{
	window_.setMouseCursorVisible(on);
}

void	sfWindow::pollEvent(sf::Event& e)
{
	window_.pollEvent(e);
}

sfWindow::sfWindow(int x, int y)
{
	window_.create(sf::VideoMode(x, y), "R-Type");
	window_.setMouseCursorVisible(false);
}

sfWindow::~sfWindow()
{
}