#include <unistd.h>
#include <iostream>
#include "GameClock.hpp"

int main()
{
  IClock* C = new GameClock();

  usleep(500000);
  C->update();
  std::cout << "Elapsed time after usleep(500000)  : " << C->getElapsedTime() << std::endl;

  sleep(1);
  C->update();
  std::cout << "Elapsed time after sleep(1)  : " << C->getElapsedTime() << std::endl;
}
