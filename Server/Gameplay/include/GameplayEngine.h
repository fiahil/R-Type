
#pragma once

#include "DlManager.h"
#include "PackedPlugin.h"
#include "Collider.h"
#include "IGameMod.h"
#include "IScenario.h"
#include "QuadTree.h"
#include "ICollidable.h"
#include "IPlayer.h"
// Ajouter l'include de la class Event

class GameplayEngine {
  Collider * coll_;
  QuadTree * quad_;
  static Dl::DlManager<PackedPlugin> * manager_;
  std::deque<IPlayer*>& players_;
public:
  GameplayEngine(std::string, std::deque<IPlayer*>&);
  ~GameplayEngine();
  IGameMod * gm_;
  IScenario * sc_;
  void handleEvent(/*Event*/);
  void plugEntity(ICollidable *);
  void update();
  bool isGameEnded() const;
  bool isPlayerDead(int) const;
};
