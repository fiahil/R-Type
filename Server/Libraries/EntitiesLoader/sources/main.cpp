#include "GameplayEngine.h"
#include "Player.h"
#include "Room.h"

int		main()
{
	std::string name1("p1"); std::string hash1("mdp1");
	std::string name2("p2"); std::string hash2("mdp2");
	std::string name3("p3"); std::string hash3("mdp3");
	std::string name4("p4"); std::string hash4("mdp4");

	Room		R;
	IService*	S = 0;

	IPlayer*	P1 = new Player(name1, hash1, S);
	IPlayer*	P2 = new Player(name2, hash2, S);
	IPlayer*	P3 = new Player(name3, hash3, S);
	IPlayer*	P4 = new Player(name4, hash4, S);
	
	R.addPlayer(P1);
	R.addPlayer(P2);
	R.addPlayer(P3);
	R.addPlayer(P4);

	P1->setStatus(true);
	P2->setStatus(true);
	P3->setStatus(true);
	P4->setStatus(true);

	R(); /* Launch Game */

	for(;;);
}