
#include <iostream>
#include <sstream>

#include "NetworkManager.h"

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

	NetworkManager	nm(s);

	nm.run();

	return 0;
}