
#include <iostream>

#include "NetworkManager.h"

int		main()
{
	std::cout << "R-Type server V1.0" << std::endl;

	NetworkManager	nm;

	nm.run();

	return 0;
}