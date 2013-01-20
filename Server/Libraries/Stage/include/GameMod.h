#pragma once

#include "IGameMod.h"

class GameMod : public IGameMod {
public:
  GameMod();
  ~GameMod();
  void onCollision(IEntity*,IEntity*);
  void onEntityDestruction(IEntity*);
  void onFire(IEntity*);
  void onLevelStart();
  void onLevelEnd();
  void onModulePlug(IEntity*);
  void onModuleUnplug(IEntity*);
  void onNewEntity(IEntity*);
  void onPickUp(IEntity*);
  void onScreenIn(IEntity*);
  void onScreenOut(IEntity*);
  void onScriptBegin(IEntity*);
  void onScriptEnd(IEntity*);
  void onUltimate(IEntity*);
};
