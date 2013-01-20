#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfJoystick.h"
#include "sfMouse.h"
#include "sfKeyboard.h"
#include "sfSpriteSheet.h"
#include "GameComponent.h"
#include "Stage.h"
#include "Skin.h"

#ifdef WIN32
#include <boost\asio.hpp>
#include <Windows.h>
#endif

extern	std::vector<skin>	skinArray;
extern	sfWindow	sfmlWin;

int main()
{
	fillArray();
	ISpriteSheet	*test = new sfSpriteSheet(skinArray[0].filePath, skinArray[0].anim, skinArray[0].frame);
	ISpriteSheet	*test2 = new sfSpriteSheet(skinArray[8].filePath, skinArray[8].anim, skinArray[8].frame);
	ISpriteSheet	*ships = new sfSpriteSheet("../Resources/Sprite/ennemy_bullet1.gif", 1, 8);
	ISpriteSheet	*boom = new sfSpriteSheet(skinArray[7].filePath, skinArray[7].anim, skinArray[7].frame);
	ISpriteSheet	*boom2 = new sfSpriteSheet("../Resources/Sprite/big_death.gif", 1, 8);
	ISpriteSheet	*bing = new sfSpriteSheet(skinArray[9].filePath, skinArray[9].anim, skinArray[9].frame);
	ISpriteSheet	*ennemy = new sfSpriteSheet("../Resources/Sprite/ennemy1.gif", 1, 8);
	
<<<<<<< HEAD
	//IInput	*input3 = new sfKeyboard();
=======

	IInput	*input3 = new sfKeyboard();
>>>>>>> 317e185242f0b1773191a19a6c54679e66905c46
	//IInput	*input2 = new sfJoystick();
	IInput	*input = new sfMouse();

	/*
	input3->autoBind(UpKey, sf::Keyboard::W);
	input3->autoBind(DownKey, sf::Keyboard::S);
	input3->autoBind(LeftKey, sf::Keyboard::A);
	input3->autoBind(RightKey, sf::Keyboard::D);
	input3->autoBind(FireKey, sf::Keyboard::Space);
	*/
		
	GameComponent	*vaisseau = new GameComponent(test, boom);
	GameComponent	*vaisseau2 = new GameComponent(test2, boom2);
	Stage st;
	st.add(vaisseau);
	st.add(vaisseau2);

	int	i = 0, o = 1;
	vaisseau2->move(5, 0); 
	//balise copiage de code
	sf::Event ev;
	while (sfmlWin.isOpen())
	{
		sfmlWin.pollEvent(ev);
		if (ev.type == sf::Event::Closed)
			sfmlWin.getWindow().close();
		Sleep(10); //TODO replace par truc utiles genre les packets udp lol
		int x = 0, y = 0;
		vaisseau->move(input->getLastInput(UpKey), input->getLastInput(LeftKey));
		//vaisseau->move(input2->getLastInput(UpKey), input2->getLastInput(LeftKey));
		/*if (input3->getLastInput(UpKey))
			y = -4;
		else if (input3->getLastInput(DownKey))
			y = 4;
		if (input3->getLastInput(LeftKey))
			x = -4;
		else if (input3->getLastInput(RightKey))
			x = 4;
		vaisseau->move(x, y);
		if (input3->isPressed(FireKey))
			vaisseau->death();
		*/
		st.update();
		sfmlWin.clear();
		st.draw();
		sfmlWin.display();
	}
	//balise fin copiage de code
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