#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfJoystick.h"
#include "sfSpriteSheet.h"

extern	sfWindow	sfmlWin;

int main()
{
	sfSpriteSheet	 test("..\\..\\Sprites\\r-typesheet42.gif", 5, 5);
	int	i = 0;
	while (sfmlWin.isOpen())
	{
		if (++i == 100)
		{
			test.playAnimation();
			i = 0;
		}
		sfmlWin.clear();
		sfmlWin.draw(test.getSprite());
		sfmlWin.display();
	}

	return 0;
}
