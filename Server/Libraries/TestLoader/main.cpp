#include "GameplayEngine.h"

int		main(int ac, char * av[])
{
	GameplayEngine * ge_ = new GameplayEngine("Monster.dll");
	for(float f = 0.f; !(ge_->sc_->isOver(f)); f += 1.f) {
		ge_->sc_->getNextEvent(f);
	}
}