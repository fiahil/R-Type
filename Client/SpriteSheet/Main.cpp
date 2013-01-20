#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfJoystick.h"
#include "sfMouse.h"
#include "sfKeyboard.h"
#include "sfSpriteSheet.h"
#include "GameComponent.h"
#include "Stage.h"
#include "Skin.h"
#include "NetworkManager.hpp"

#include <unistd.h> // tmp

#ifdef WIN32
#include <boost\asio.hpp>
#include <Windows.h>
#endif

extern	std::vector<skin>	skinArray;
extern	sfWindow	sfmlWin;

int main(int ac, char **av)
{
  NetworkManager NM(av);
	fillArray();
	ISpriteSheet	*test = new sfSpriteSheet(skinArray[0].filePath, skinArray[0].anim, skinArray[0].frame);
	ISpriteSheet	*test2 = new sfSpriteSheet(skinArray[8].filePath, skinArray[8].anim, skinArray[8].frame);
	ISpriteSheet	*ships = new sfSpriteSheet("../Resources/Sprite/boss.gif", 1, 9);
	ISpriteSheet	*boom = new sfSpriteSheet(skinArray[7].filePath, skinArray[7].anim, skinArray[7].frame);
	ISpriteSheet	*boom2 = new sfSpriteSheet("../Resources/Sprite/boss_death.gif", 1, 9);
	ISpriteSheet	*bing = new sfSpriteSheet(skinArray[9].filePath, skinArray[9].anim, skinArray[9].frame);
	ISpriteSheet	*ennemy = new sfSpriteSheet("../Resources/Sprite/ennemy1.gif", 1, 8);
	
	IInput	*input3 = new sfKeyboard();
	//IInput	*input2 = new sfJoystick();
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

	int	i = 0, o = 1;
	vaisseau2->move(5, 0); 
	//balise copiage de code
	sf::Event ev;
	while (sfmlWin.isOpen())
	{
		int x = 0, y = 0;
		sfmlWin.pollEvent(ev);
		if (ev.type == sf::Event::Closed)
			sfmlWin.getWindow().close();
		usleep(100000); //TODO replace par truc utiles genre les packets udp lol
		//vaisseau->move(input->getLastInput(UpKey), input->getLastInput(LeftKey));
		vaisseau2->move(input3->getLastInput(UpKey), input3->getLastInput(LeftKey));
		if (input3->getLastInput(UpKey))
			y = -4;
		else if (input3->getLastInput(DownKey)) {
			y = 4;
			Move a;
			a.id = 666;
			a.x = 4;
			a.y = 12;
			a.speedx = 24;
			a.speedy = 32;
			ICommand* plop = new Command<Move>(a, CommandType::MOVE);
			NM.push_back(plop);
		}
		if (input3->getLastInput(LeftKey))
			x = -4;
		else if (input3->getLastInput(RightKey))
			x = 4;
		vaisseau->move(x, y);
		if (input3->isPressed(FireKey))
			vaisseau2->death();
		
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
