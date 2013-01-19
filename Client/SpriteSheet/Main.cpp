#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfJoystick.h"
#include "sfSpriteSheet.h"
#include "GameComponent.h"

extern	sfWindow	sfmlWin;

int main()
{
	ISpriteSheet	*test = new sfSpriteSheet("..\\Resources\\Sprite\\round_bot.gif", 1, 12);
	ISpriteSheet	*test2 = new sfSpriteSheet("..\\Resources\\Sprite\\r-typesheet42.gif", 5, 5);
	ISpriteSheet	*ships = new sfSpriteSheet("..\\Resources\\Sprite\\ennemy_bullet1.gif", 1, 8);
	ISpriteSheet	*boom = new sfSpriteSheet("..\\Resources\\Sprite\\little_death.gif", 1, 6);
	ISpriteSheet	*boom2 = new sfSpriteSheet("..\\Resources\\Sprite\\little_death.gif", 1, 6);
	ISpriteSheet	*bing = new sfSpriteSheet("..\\Resources\\Sprite\\big_death.gif", 1, 8);
	ISpriteSheet	*ennemy = new sfSpriteSheet("..\\Resources\\Sprite\\ennemy1.gif", 1, 8);
	
	GameComponent	vaisseau(test, boom);
	GameComponent	vaisseau2(test2, boom2);

	int	i = 0, o = 1;
	ships->moveTo(-10 , 10);
	vaisseau.move(1,4);
	vaisseau2.move(4, 1);
	vaisseau.update();
	vaisseau.update();

	while (sfmlWin.isOpen())
	{
		if (++i == 100)
		{
			ennemy->playAnimation(0);
			ships->playAnimation(0);
			i = 0;
		}
		if (i == 0)
		{
			++o;
			if (o == 30)
			{
				vaisseau.death();
			}
			if (o == 50)
				vaisseau2.death();
			vaisseau.update();
			vaisseau2.update();
			ennemy->moveFrom(1,1);
			ships->moveFrom(1,1);
		}
		sfmlWin.clear();
		vaisseau.draw();
		vaisseau2.draw();
		//ennemy->draw();
		//ships->draw();
		sfmlWin.display();
	}

	return 0;
}
