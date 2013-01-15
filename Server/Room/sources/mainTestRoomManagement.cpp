#include <exception>
#include "RoomManager.h"
#include "Room.h"
#include "Player.h"

#include <iostream> // remove

int		main()
{
	std::cout << "\n---- BEGIN ----\n" << std::endl;

	std::string	nico("Nico");
	std::string	papa("Papa");
	std::string	alex("Alex");
	std::string	quentin("Quentin");
	std::string	matthieu("Matthieu");
	IService * S1 = (IService *)&nico;	// cheat for giving a valid address to ptr S..
	IService * S2 = (IService *)&papa;
	IService * S3 = (IService *)&alex;
	IService * S4 = (IService *)&quentin;
	IService * S5 = (IService *)&matthieu;

	RoomManager roomManager;

	int r1 = roomManager.createRoom();	// ID of first Room
	int r2 = roomManager.createRoom();	// ID of second Room

	std::cout << "\nRoom-1 ID = " << r1 << std::endl;
	std::cout << "Room-2 ID = " << r2 << std::endl;

std::cout << "\n===== TEST [HALL] =====" << std::endl;

	/* Adding players in Hall */
	roomManager.addPlayerToHall(nico, nico, S1);		 // ID 0
	roomManager.addPlayerToHall(papa, papa, S2);		 // ID 1
	roomManager.addPlayerToHall(alex, alex, S3);		 // ID 2
	roomManager.addPlayerToHall(quentin, quentin, S4);	 // ID 3
	roomManager.addPlayerToHall(matthieu, matthieu, S5); // ID 4

	/* Removing some player from Hall */

	/* UNSAFE : {getPlayerFromName} may not work and return 0, so test the method before using IPlayer */
	roomManager.removePlayerFromHall(roomManager.getPlayerFromName(matthieu)->getId());

	/* SAFE */
	IPlayer *test0 =	roomManager.getPlayerFromName(matthieu);
	if (test0)			roomManager.removePlayerFromHall(test0->getId());	// should fail : matthieu already removed
	else				std::cerr << "getPlayerFromName FAILED : matthieu already removed" << std::endl;

std::cout << "\n===== TEST [ROOM] =====" << std::endl;

	/* Adding players in Room 1 */
	roomManager.clonePlayerFromHallToRoom(r1, roomManager.getPlayerFromName(nico)->getId());
	roomManager.clonePlayerFromHallToRoom(r1, roomManager.getPlayerFromName(papa)->getId());
	roomManager.clonePlayerFromHallToRoom(r1, roomManager.getPlayerFromName(alex)->getId());
	roomManager.clonePlayerFromHallToRoom(r1, roomManager.getPlayerFromName(quentin)->getId());

	IPlayer *test1 =	roomManager.getPlayerFromName(matthieu);
	if (test1) 			roomManager.clonePlayerFromHallToRoom(r1, test1->getId());	// should fail : matthieu is not in hall
	else				std::cerr << "getPlayerFromName FAILED : matthieu is not in hall" << std::endl;

	roomManager.addPlayerToHall(matthieu, matthieu, S5);				// so let's add matthieu in hall

	IPlayer *test2 =	roomManager.getPlayerFromName(matthieu);
	if (test2) 			roomManager.clonePlayerFromHallToRoom(r1, test2->getId());	// should fail : room is full
	else				std::cerr << "getPlayerFromName FAILED : room is full" << std::endl;

	/* Removing some player from Room */
	roomManager.removePlayerFromRoom(r1, roomManager.getPlayerFromName(nico)->getId());

	IPlayer *test3 =	roomManager.getPlayerFromName(nico);
	if (test3) 			roomManager.removePlayerFromRoom(r1, test3->getId());		// should fail : nico already removed
	else				std::cerr << "getPlayerFromName FAILED : nico already removed" << std::endl;

	/* link room to threadPool*/
	roomManager.linkRoomToThreadPool(r1);
	
std::cout << "\n===== TEST [SERVICE Compatibility] =====" << std::endl;

/* FROM NAME*/
	IPlayer	*get1 = roomManager.getPlayerFromName(nico);
	if (get1)		std::cout << "\ngetPlayerFromName Ok : " << get1->getName() << std::endl;
	else			std::cerr << "Error : getPlayerFromName Fail Name" << std::endl;

	std::string testname = "SpongeBob";		// should fail : unknown name
	IPlayer	*get2 = roomManager.getPlayerFromName(testname);
	if (get2)		std::cout << "\ngetPlayerFromName Ok : " << get2->getName() << std::endl;
	else			std::cerr << "Error : getPlayerFromName Fail Name !" << std::endl;


/* FROM HALL*/
	IPlayer	*get3 = roomManager.getPlayerFromHall(S1);
	if (get3)		std::cout << "\ngetPlayerFromHall Ok : name = " << get3->getName() << std::endl;
	else			std::cerr << "Error : getPlayerFromHall Fail S !" << std::endl;

	IPlayer	*get5 = roomManager.getPlayerFromHall(0);	// sould fail, invalid Service
	if (get5)		std::cout << "\ngetPlayerFromHall Ok : name = " << get5->getName() << std::endl;
	else			std::cerr << "Error : getPlayerFromHall Fail Service !" << std::endl;

/* FROM Room*/
	IPlayer	*get4 = roomManager.getPlayerFromRoom(S2, r1);
	if (get4)		std::cout << "\ngetPlayerFromRoom Ok : name = " << get4->getName() << std::endl;
	else			std::cerr << "Error : getPlayerFromRoom Fail Service or RoomId invalid !" << std::endl;

	IPlayer	*get6 = roomManager.getPlayerFromRoom(S1, -1);	// sould fail, invalid room id
	if (get6)		std::cout << "\ngetPlayerFromRoom Ok : name = " << get5->getName() << std::endl;
	else			std::cerr << "Error : getPlayerFromRoom Fail Service or RoomId invalid !" << std::endl;

	IPlayer	*get7 = roomManager.getPlayerFromRoom(0, r1);	// sould fail, invalid Service
	if (get7)		std::cout << "\ngetPlayerFromRoom Ok : name = " << get7->getName() << std::endl;
	else			std::cerr << "Error : getPlayerFromRoom Fail Service or RoomId invalid !" << std::endl;

/* Other */
	IRoom * Rt1	= roomManager.getRoomById(r1);
	if (Rt1)		std::cout << "\ngetRoomById Ok : Id = " << Rt1->getId() << std::endl;
	else			std::cerr << "Error : getRoomById : RoomId invalid !" << std::endl;

	IRoom * Rt2	= roomManager.getRoomById(-1);				// sould fail, invalid id
	if (Rt2)		std::cout << "\ngetRoomById Ok : Id = " << Rt2->getId() << std::endl;
	else			std::cerr << "Error : getRoomById : RoomId invalid !" << std::endl;

	/* Removing some room */
	roomManager.removeRoom(r1);
	roomManager.removeRoom(r2);


std::cout << "\n===== END OF TEST TIME =====" << std::endl;
	for (;;);
	return 0;
}
