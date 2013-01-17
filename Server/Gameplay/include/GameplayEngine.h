
#pragma once

#include "DlManager.h"
#include "PackedPlugin.h"
#include "Collider.h"
#include "IGameMod.h"
#include "IScenario.h"
#include "QuadTree.h"
// Ajouter l'include de la class Event

class GameplayEngine {
  Collider * coll_;
  QuadTree * quad_;
  IGameMod * gm_;
  IScenario * sc_;
  static Dl::DlManager<PackedPlugin> * manager_;
public:
  GameplayEngine(std::string);
  ~GameplayEngine();
  void handleEvent(/*Event*/);
  void plugEntity(IEntity *);
  void update();
};
