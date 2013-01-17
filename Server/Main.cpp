
#include "logger.h"
#include <sstream>

#include "NetworkManager.h"
#include "logger.h"

#ifdef WIN32
# pragma comment(lib, "WS2_32")
#endif

int		main(int ac, char *av[])
{
	std::string		port("42666");

	if (ac > 1)
	{
		port = av[1];
	}
	
	std::stringstream ss(port);
	unsigned short s;
	ss >> s;

	LOG << "Launching server on port " << port << std::endl;

	NetworkManager	nm(s);

	nm.run();

	return 0;
}
