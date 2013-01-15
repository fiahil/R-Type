#pragma once

#include "IEntity.h"
#include "DlManager.h "

class IGameMod : public DL::IDlPlugin {
public:
  virtual void onCollision(IEntity*,IEntity*) = 0;
  virtual void onEntityDestruction(IEntity*) = 0;
  virtual void onFire(IEntity*) = 0;
  virtual void onLevelStart() = 0;
  virtual void onLevelEnd() = 0;
  virtual void onModulePlug(IEntity*) = 0;
  virtual void onModuleUnplug(IEntity*) = 0;
  virtual void onNewEntity(IEntity*) = 0;
  virtual void onPickUp(IEntity*) = 0;
  virtual void onScreenIn(IEntity*) = 0;
  virtual void onScreenOut(IEntity*) = 0;
  virtual void onScriptBegin(IEntity*) = 0;
  virtual void onScriptEnd(IEntity*) = 0;
  virtual void onUltimate(IEntity*) = 0;
  virtual std::string const& getId() const = 0;
};
