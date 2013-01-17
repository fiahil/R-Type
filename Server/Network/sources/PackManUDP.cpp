
#include	"CSCommand.h"
#include	"PackManUDP.h"

static std::map<eCommandType, ICommand* (*)(const UDPPacket*)> initCommandTab() {
	std::map<eCommandType, ICommand* (*)(const UDPPacket*)> cmdMap;
	cmdMap.insert(std::make_pair(MOVE, &PackManUDP::unpack_t<Move>));
	cmdMap.insert(std::make_pair(FIRE, &PackManUDP::unpack_t<Fire>));
	return (cmdMap);
}

std::map<eCommandType, ICommand* (*)(const UDPPacket*)> PackManUDP::cmdTab = initCommandTab();
