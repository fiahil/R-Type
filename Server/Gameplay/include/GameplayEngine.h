#pragma once

#include "Collider.h"
#include "IGameMod.h"
#include "QuadTree.h"
// Ajouter l'include de la class Event


class GameplayEngine {
  Collider coll_;
  QuadTree quad_;
  IGameMod * gm_;
public:
  GameplayEngine();
  ~GameplayEngine();
  void handleEvent(Event);
  void plugEntity(IEntity *);
  void update();
};
