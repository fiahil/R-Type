#include "GameplayEngine.h"

int		main()
{
	GameplayEngine * ge_ = new GameplayEngine("Stage_1.dll");
	for(float f = 0.f; !(ge_->sc_->isOver()); f += 1.f) {
		ge_->sc_->getNextEvent(f);
	}

	for(;;);
}