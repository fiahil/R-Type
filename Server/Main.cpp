
#include <iostream>
#include <sstream>

#include "NetworkManager.h"
#include "logger.h"

int		main(int ac, char *av[])
{
	std::string		port("42666");
	Logger			test(std::cout, "[Debug]");

	if (ac > 1)
	{
		port = av[1];
	}
	
	std::stringstream ss(port);
	unsigned short s;
	ss >> s;

	test << "lol " << std::endl;

	NetworkManager	nm(s);

	nm.run();

	return 0;
}