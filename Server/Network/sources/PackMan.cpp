
#include <utility>
#include "PackMan.h"

static std::map<eRequestType, IRequest* (*)(TCPPacket*)>	init_request_tab()
{
	std::map<eRequestType, IRequest* (*)(TCPPacket*)>	map;
	
	map.insert(std::make_pair(CONNECT, &PackMan::unpack_T<Connect>));
	map.insert(std::make_pair(CREATE_ROOM, &PackMan::unpack_T<CreateRoom>));
	map.insert(std::make_pair(LEAVE_ROOM, &PackMan::unpack_T<LeaveRoom>));
	map.insert(std::make_pair(JOIN_ROOM, &PackMan::unpack_T<JoinRoom>));
	map.insert(std::make_pair(INVITE_PLAYER, &PackMan::unpack_T<InvitePlayer>));
	map.insert(std::make_pair(SET_GAME_PARAM, &PackMan::unpack_T<SetGameParam>));
	map.insert(std::make_pair(LAUNCH_GAME, &PackMan::unpack_T<LaunchGame>));
	map.insert(std::make_pair(PING, &PackMan::unpack_T<Ping>));
	map.insert(std::make_pair(READY, &PackMan::unpack_T<Ready>));

	return map;
}

std::map<eRequestType, IRequest* (*)(TCPPacket*)>	PackMan::request_tab = init_request_tab();
