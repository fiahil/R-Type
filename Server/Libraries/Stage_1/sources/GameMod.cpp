#include "GameMod.h"

GameMod::GameMod() {}

GameMod::~GameMod() {}

template<typename T, typename U>
U *	cast_entity(T * m)
{
	return (dynamic_cast<U *>(m));
}

void GameMod::onCollision(IEntity * x,IEntity * y) {
	IDestroyable *	tmp;

	if (tmp = cast_entity<IEntity, IDestroyable>(x))
		tmp->destroy();
	if (tmp = cast_entity<IEntity, IDestroyable>(y))
		tmp->destroy();
}

void GameMod::onEntityDestruction(IEntity * x) {
	(void)x;
}

void GameMod::onFire(IEntity * x) {
	(void)x;
}

void GameMod::onLevelStart() {

}

void GameMod::onLevelEnd() {

}

void GameMod::onModulePlug(IEntity * x) {
	(void)x;
}

void GameMod::onModuleUnplug(IEntity * x) {
	(void)x;
}

void GameMod::onNewEntity(IEntity * x) {
	(void)x;
}

void GameMod::onPickUp(IEntity * x) {
	(void)x;
}

void GameMod::onScreenIn(IEntity * x) {
	(void)x;
}

void GameMod::onScreenOut(IEntity * x) {
	(void)x;
}

void GameMod::onScriptBegin(IEntity * x) {
	(void)x;
}

void GameMod::onScriptEnd(IEntity * x) {
	(void)x;
}

void GameMod::onUltimate(IEntity * x) {
	(void)x;
}
