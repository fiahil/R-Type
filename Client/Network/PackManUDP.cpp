
#include	"Command.h"
#include	"Cmd.h"
#include	"PackManUDP.h"

static std::map<CommandType::eCommandType, ICommand* (*)(const UDPPacket*)> initCommandTab() {
	std::map<CommandType::eCommandType, ICommand* (*)(const UDPPacket*)> cmdMap;
	cmdMap.insert(std::make_pair(CommandType::MOVE, &PackManUDP::unpack_t<Move>));
	cmdMap.insert(std::make_pair(CommandType::FIRE, &PackManUDP::unpack_t<Fire>));
	return (cmdMap);
}

std::map<CommandType::eCommandType, ICommand* (*)(const UDPPacket*)> PackManUDP::cmdTab = initCommandTab();
