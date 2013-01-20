#include <SFML/Graphics.hpp>
#include <iostream>

#ifdef WIN32
#include <boost\asio.hpp>
#include <Windows.h>
#endif

extern	std::vector<skin>	skinArray;
extern	sfWindow	sfmlWin;

int main(int ac, char **av)
{
  if (ac == 3)
    {

      fillArray();
      // ISpriteSheet	*test = new sfSpriteSheet(skinArray[0].filePath, skinArray[0].anim, skinArray[0].frame);
      // ISpriteSheet	*bing = new sfSpriteSheet(skinArray[9].filePath, skinArray[9].anim, skinArray[9].      // ISpriteSheet	*ennemy = new sfSpriteSheet("../../Resources/Sprite/ennemy1.gif", 1, 8);
      // IInput	*input2 = new sfJoystick();
      //IInput	*input = new sfMouse();

	
      input3->autoBind(UpKey, sf::Keyboard::W);
      input3->autoBind(DownKey, sf::Keyboard::S);
      input3->autoBind(LeftKey, sf::Keyboard::A);
      input3->autoBind(RightKey, sf::Keyboard::D);
      input3->autoBind(FireKey, sf::Keyboard::Space);
		
      GameComponent	*vaisseau = new GameComponent(ships, boom2);
      GameComponent	*vaisseau2 = new GameComponent(test2, boom);
      Stage st;
      st.add(vaisseau);
      st.add(vaisseau2);

      // int	i = 0, o = 1;
      vaisseau2->move(5, 0); 
      //balise copiage de code
      while (sfmlWin.isOpen())
	{
	}
      //balise fin copiage de code
    }
  else
    std::cout << "Usage : ./client [ip] [port]" << std::endl;
  return 0;
}
/*
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
*/
