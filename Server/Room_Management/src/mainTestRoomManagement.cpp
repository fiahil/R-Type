
#include "RoomManager.h"
#include "Room.h"
#include "Player.h"

#include <iostream> // remove

int		main()
{
	std::cout << "\n---- BEGIN ----\n" << std::endl;

	IPlayer *p1 = new Player();
	IPlayer *p2 = new Player();
	IPlayer *p3 = new Player();
	IPlayer *p4 = new Player();
	IPlayer *p5 = new Player();

	RoomManager roomManager;

	int r1 = roomManager.createRoom();	// ID of first Room
	int r2 = roomManager.createRoom();	// ID of second Room

	std::cout << "\nPlayer-1 ID = " << p1->getId() << std::endl;
	std::cout << "Player-2 ID = " << p2->getId() << std::endl;
	std::cout << "Player-3 ID = " << p3->getId() << std::endl;
	std::cout << "Player-4 ID = " << p4->getId() << std::endl;

	std::cout << "\nRoom-1 ID = " << r1 << std::endl;
	std::cout << "Room-2 ID = " << r2 << std::endl;

std::cout << "\n===== TEST TIME =====" << std::endl;

std::cout << "\n===== TEST [HALL] =====" << std::endl;

	roomManager.roomSpeach();			// should have 2 EMPTY rooms
	roomManager.hallSpeach();			// should have 0 players

	/* Adding players in Hall */
	roomManager.addPlayerToHall(p1);
	roomManager.addPlayerToHall(p2);
	roomManager.addPlayerToHall(p3);
	roomManager.addPlayerToHall(p4);
	roomManager.addPlayerToHall(p5);
	roomManager.hallSpeach();			// should have 5 players now

	/* Removing some player from Hall */
	roomManager.removePlayerFromHall(p5->getId());
	roomManager.removePlayerFromHall(p5->getId());	// should fail : p5 already removed
	roomManager.removePlayerFromHall(-17);			// should fail : invalid id


std::cout << "\n===== TEST [ROOM] =====" << std::endl;

	roomManager.hallSpeach();			// should have 4 players now
	roomManager.roomSpeach();			// should have 2 EMPTY rooms

	/* Adding players in Room 1 */
	roomManager.clonePlayerFromHallToRoom(r1, p1->getId());
	roomManager.clonePlayerFromHallToRoom(r1, p2->getId());
	roomManager.clonePlayerFromHallToRoom(r1, p3->getId());
	roomManager.clonePlayerFromHallToRoom(r1, p4->getId());

	roomManager.clonePlayerFromHallToRoom(r1, p5->getId());	// should fail : p5 is not in hall
	roomManager.addPlayerToHall(p5);						// so let's add p5 in hall

	roomManager.clonePlayerFromHallToRoom(r1, p5->getId());	// should fail : room is full
	roomManager.clonePlayerFromHallToRoom(r1, -17);			// should fail : invalid player ID

	roomManager.roomSpeach();		// should have 2 rooms : r1 [p1, p2, p3, p4], and EMPTY r2

	/* Removing some player from Room */
	roomManager.removePlayerFromRoom(r1, p1->getId());
	roomManager.removePlayerFromRoom(r1, p1->getId());		// should fail : p1 already removed
	roomManager.removePlayerFromRoom(r1, -17);				// should fail : -17 invalid id

	roomManager.roomSpeach();		// should have 2 rooms : r1 [p2, p3, p4], and EMPTY r2

	/* Removing some room */
	roomManager.removeRoom(r1);
	roomManager.removeRoom(r2);
	roomManager.roomSpeach();	// should have 0 room



	/*
		TO DO : tests unitaires sur [isFull] 
		et [setNbGames] (conflits eventuels avec createRoom apres? etc)
	*/

	std::cout << "\n===== END OF TEST TIME =====" << std::endl;

	std::cout << "\n---- END ----" << std::endl;
	for (;;);
	return 0;
}