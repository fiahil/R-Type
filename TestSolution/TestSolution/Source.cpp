#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Texture texture;

	if (!texture.loadFromFile("..\\Resources\\10.png"))
		std::cerr << "error" << std::endl;
	
	sf::Sprite shape(texture);

	shape.setPosition(0, 0);

	window.setVerticalSyncEnabled(true);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		if (event.type == sf::Event::KeyPressed)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
						shape.move(0, -10);	
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						shape.move(-10, 0);	
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						shape.move(0, 10);	
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						shape.move(10, 0);	
				}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
