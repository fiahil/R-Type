#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfJoystick.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Texture texture;

	if (!texture.loadFromFile("..\\Resources\\10.png"))
		std::cerr << "error" << std::endl;
	
	sf::Sprite shape(texture);

	shape.setPosition(0, 0);

	window.setVerticalSyncEnabled(true);
	sfJoystick	j;
	while (window.isOpen())
	{
		shape.move(j.getLastInput(UpKey), j.getLastInput(LeftKey));
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
