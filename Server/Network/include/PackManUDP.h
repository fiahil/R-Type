
#pragma once

#include	<map>
#include	<cassert>

#include	"ICommand.h"
#include	"UDPPacket.h"
#include	"Command.h"

class PackManUDP
{
private:
	static std::map<eCommandType, ICommand* (*)(const UDPPacket*)> cmdTab;

	template<typename S>
	static void* MemSet(S* dest, std::size_t c)
	{
		unsigned char *Tdest = reinterpret_cast<unsigned char*>(dest);
		unsigned char const *Tc = reinterpret_cast<unsigned char const*>(dest) + c;

		while (Tdest != Tc)
			*(Tdest++) = 0;
		return (dest);
	}

public:
	template<typename S, typename U>
	static void* Memcpy(U* dest, S* src, std::size_t c)
	{
		unsigned char const *Tsrc = reinterpret_cast<unsigned char const*>(src);
		unsigned char *Tdest = reinterpret_cast<unsigned char *>(dest);
		unsigned char const *Tc = reinterpret_cast<unsigned char const*>(src) + c;

		PackManUDP::MemSet(Tdest, c);
		while (Tsrc != Tc)
			*(Tdest++) = *(Tsrc++);
		return (dest);
	}

	template<class T>
	static UDPPacket* pack(T* t, int16_t player, eCommandType type, int32_t clock)
	{
		if (!t)
			return (0);
		UDPPacket* pack = new UDPPacket();
		pack->H.size = sizeof(T) + sizeof(pack->H);
		pack->H.player = player;
		pack->H.type = type;
		pack->clock = clock;
		PackManUDP::Memcpy(pack->value, t, sizeof(T));
		return (pack);
	}

	template<class T>
	static ICommand* unpack_t(const UDPPacket* pack)
	{
		if (!pack)
			return (0);
		T packCmd;
		PackManUDP::Memcpy(&packCmd, pack->value, pack->H.size - sizeof(pack->H));
		ICommand* cmd = new Command<T>(packCmd, static_cast<eCommandType>(pack->H.type));
		return (cmd);
	}

	static ICommand* unpack(const UDPPacket* pack)
	{
		std::map<eCommandType, ICommand* (*)(const UDPPacket*)>::const_iterator cmd = PackManUDP::cmdTab.find(static_cast<eCommandType>(pack->H.type));

		if (cmd != PackManUDP::cmdTab.end())
			return (cmd->second(pack));
		else
			return (0);
	}

	
};