#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfJoystick.h"
#include "sfSpriteSheet.h"
#include "GameComponent.h"
#include "Stage.h"

extern	sfWindow	sfmlWin;

int main()
{
	ISpriteSheet	*test = new sfSpriteSheet("..\\Resources\\Sprite\\player_bullet.gif", 1, 2);
	ISpriteSheet	*test2 = new sfSpriteSheet("..\\Resources\\Sprite\\big_monster.gif", 1, 6);
	ISpriteSheet	*ships = new sfSpriteSheet("..\\Resources\\Sprite\\ennemy_bullet1.gif", 1, 8);
	ISpriteSheet	*boom = new sfSpriteSheet("..\\Resources\\Sprite\\death_bullet_player.gif", 1, 5);
	ISpriteSheet	*boom2 = new sfSpriteSheet("..\\Resources\\Sprite\\little_death.gif", 1, 6);
	ISpriteSheet	*bing = new sfSpriteSheet("..\\Resources\\Sprite\\big_death.gif", 1, 8);
	ISpriteSheet	*ennemy = new sfSpriteSheet("..\\Resources\\Sprite\\ennemy1.gif", 1, 8);
	
	GameComponent	*vaisseau = new GameComponent(test, boom);
	GameComponent	*vaisseau2 = new GameComponent(test2, boom2);
	Stage st;
	st.add(vaisseau);
	st.add(vaisseau2);

	int	i = 0, o = 1;
	ships->moveTo(-10 , 10);
	vaisseau->move(1,4);
	vaisseau2->move(4, 1); 

	while (sfmlWin.isOpen())
	{
		if (++i == 250)
		{
			i = 0;
		}
		if (i == 0)
		{
			++o;
			if (o == 60)
			{
				vaisseau->death();
			}
			st.update();
			ennemy->moveFrom(1,1);
			ships->moveFrom(1,1);
		}
		sfmlWin.clear();
		st.draw();
		//vaisseau.draw();
		//vaisseau2.draw();
		sfmlWin.display();
	}

	return 0;
}
