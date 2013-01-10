
#include <exception>
#include "RoomManager.h"
#include "Room.h"
#include "Player.h"

#include <iostream> // remove


int		main()
{
	std::cout << "\n---- BEGIN ----\n" << std::endl;

	IService * S;
	std::string	nico("Nico");
	std::string	papa("Papa");
	std::string	alex("Alex");
	std::string	quentin("Quentin");
	std::string	matthieu("Matthieu");

	RoomManager roomManager;

	int r1 = roomManager.createRoom();	// ID of first Room
	int r2 = roomManager.createRoom();	// ID of second Room

	std::cout << "\nRoom-1 ID = " << r1 << std::endl;
	std::cout << "Room-2 ID = " << r2 << std::endl;

std::cout << "\n===== TEST [HALL] =====" << std::endl;

	/* Adding players in Hall */
	roomManager.addPlayerToHall(nico, nico, S);			// ID 0
	roomManager.addPlayerToHall(papa, papa, S);			// ID 1
	roomManager.addPlayerToHall(alex, alex, S);			// ID 2
	roomManager.addPlayerToHall(quentin, quentin, S);	// ID 3
	roomManager.addPlayerToHall(matthieu, matthieu, S);	// ID 4

	/* Removing some player from Hall */

	roomManager.removePlayerFromHall(roomManager.getPlayerFromName(matthieu)->getId());

	IPlayer *test0;
	test0 = roomManager.getPlayerFromName(matthieu);
	if (test0)
		roomManager.removePlayerFromHall(test0->getId());	// should fail : matthieu already removed
	else
		std::cerr << "getPlayerFromName FAILED : matthieu already removed" << std::endl;

	std::cout << "\n===== TEST [ROOM] =====" << std::endl;

	/* Adding players in Room 1 */
	roomManager.clonePlayerFromHallToRoom(r1, roomManager.getPlayerFromName(nico)->getId());
	roomManager.clonePlayerFromHallToRoom(r1, roomManager.getPlayerFromName(papa)->getId());
	roomManager.clonePlayerFromHallToRoom(r1, roomManager.getPlayerFromName(alex)->getId());
	roomManager.clonePlayerFromHallToRoom(r1, roomManager.getPlayerFromName(quentin)->getId());

	IPlayer *test1;
	test1 = roomManager.getPlayerFromName(matthieu);
	if (test1)
		roomManager.clonePlayerFromHallToRoom(r1, test1->getId());	// should fail : matthieu is not in hall
	else
		std::cerr << "getPlayerFromName FAILED : matthieu is not in hall" << std::endl;

	roomManager.addPlayerToHall(matthieu, matthieu, S);												// so let's add matthieu in hall

	IPlayer *test2;
	test2 = roomManager.getPlayerFromName(matthieu);
	if (test2)
		roomManager.clonePlayerFromHallToRoom(r1, test2->getId());	// should fail : room is full
	else
		std::cerr << "getPlayerFromName FAILED : room is full" << std::endl;

	/* Removing some player from Room */
	roomManager.removePlayerFromRoom(r1, roomManager.getPlayerFromName(nico)->getId());

	IPlayer *test3;
	test3 = roomManager.getPlayerFromName(nico);
	if (test3)
		roomManager.removePlayerFromRoom(r1, test3->getId());		// should fail : nico already removed
	else
		std::cerr << "getPlayerFromName FAILED : nico already removed" << std::endl;

	/* Removing some room */
	roomManager.removeRoom(r1);
	roomManager.removeRoom(r2);

	std::cout << "\n===== END OF TEST TIME =====" << std::endl;
	for (;;);
	return 0;
}
