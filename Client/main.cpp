#include	<iostream>
#include	"GameManager.h"

int		main(int ac, char **av)
{
  if (ac == 3)
    {
      // IGameManager*	IGM = new GameManager(av);
      GameManager::GM = new GameManager(av);
      GameManager::GM->run();
    }
  else
    std::cout << "Usage : ./client [ip] [port]" << std::endl;
  return (0);
}
