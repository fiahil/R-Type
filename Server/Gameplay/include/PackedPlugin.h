#pragma once

#include "DlManager.h"
#include "IGameMod.h"
#include "IScenario.h"

class PackedPlugin : public IDlPlugin {
  IGameMod * gm_;
  IScenario * sc_;
public:
  PackedPlugin();
  ~PackedPlugin();
  IGameMod * getGM() const;
  IScenario * getSC() const;
};
