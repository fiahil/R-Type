#include "GameMod.h"

GameMod::GameMod() {}

GameMod::~GameMod() {}

template<typename T, typename U>
U *	cast_entity(T * m)
{
	return (dynamic_cast<U *>(m));
}

void GameMod::onCollision(IEntity * x, IEntity * y) {
	IDestroyable *	tmp;

	if ((tmp = cast_entity<IEntity, IDestroyable>(x)))
		tmp->destroy();
	if ((tmp = cast_entity<IEntity, IDestroyable>(y)))
		tmp->destroy();
}

void GameMod::onEntityDestruction(IEntity *) {
}

void GameMod::onFire(IEntity *) {
}

void GameMod::onLevelStart() {
}

void GameMod::onLevelEnd() {
}

void GameMod::onModulePlug(IEntity *) {
}

void GameMod::onModuleUnplug(IEntity *) {
}

void GameMod::onNewEntity(IEntity *) {
}

void GameMod::onPickUp(IEntity *) {
}

void GameMod::onScreenIn(IEntity *) {
}

void GameMod::onScreenOut(IEntity *) {
}

void GameMod::onScriptBegin(IEntity *) {
}

void GameMod::onScriptEnd(IEntity *) {
}

void GameMod::onUltimate(IEntity *) {
}
