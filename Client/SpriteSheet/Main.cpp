#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfJoystick.h"
#include "sfSpriteSheet.h"
#include "GameComponent.h"
#include "Stage.h"

extern	sfWindow	sfmlWin;
/*
int main()
{
	ISpriteSheet	*test = new sfSpriteSheet("..\\Resources\\Sprite\\r-typesheet42.gif", 5, 5);
	ISpriteSheet	*test2 = new sfSpriteSheet("..\\Resources\\Sprite\\big_monster.gif", 1, 6);
	ISpriteSheet	*ships = new sfSpriteSheet("..\\Resources\\Sprite\\ennemy_bullet1.gif", 1, 8);
	ISpriteSheet	*boom = new sfSpriteSheet("..\\Resources\\Sprite\\death_bullet_player.gif", 1, 5);
	ISpriteSheet	*boom2 = new sfSpriteSheet("..\\Resources\\Sprite\\big_death.gif", 1, 8);
	ISpriteSheet	*bing = new sfSpriteSheet("..\\Resources\\Sprite\\big_death.gif", 1, 8);
	ISpriteSheet	*ennemy = new sfSpriteSheet("..\\Resources\\Sprite\\ennemy1.gif", 1, 8);
	
	GameComponent	*vaisseau = new GameComponent(test, boom);
	GameComponent	*vaisseau2 = new GameComponent(test2, boom2);
	Stage st;
	st.add(vaisseau);
	st.add(vaisseau2);

	int	i = 0, o = 1;
	test->moveTo(0, 100);
	//vaisseau->move(0, 100);
	vaisseau2->move(5, 0); 

	while (sfmlWin.isOpen())
	{
		if (++i == 250)
		{
			i = 0;
		}
		if (i == 0)
		{
			++o;
			vaisseau->move(o + 15 * sin(o), (60 * cos(o)));
			if (o == 35)
				vaisseau2->death();
			st.update();
		}
		sfmlWin.clear();
		st.draw();
		sfmlWin.display();
	}

	return 0;
}
*/

#include	<iostream>
#include	"NetworkManager.hpp"

int		main(int ac, char **av)
{
  if (ac == 3)
    {
      INetworkManager*	NM = new NetworkManager(av);
      NM->run();
    }
  else
    std::cout << "Usage : ./ClientRtype [ip] [port]" << std::endl;
}