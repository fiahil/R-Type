#include "sfWindow.h"

sfWindow	sfmlWin;

sf::Window&	sfWindow::getWindow()
{
	return this->window_;
}

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

void	sfWindow::draw(sf::Drawable const& drawable)
{
	window_.draw(drawable);
}

bool	sfWindow::isOpen()
{
	return window_.isOpen();
}

void	sfWindow::clear()
{
	window_.clear();
}

void	sfWindow::display()
{
	window_.display();
}

sfWindow::sfWindow(int x, int y)
{
	window_.create(sf::VideoMode(x, y), "R-Type");
}

sfWindow::~sfWindow()
{
}