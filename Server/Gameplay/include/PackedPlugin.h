#pragma once

#include "DlManager.h"
#include "IGameMod.h"
#include "IScenario.h"

class PackedPlugin : public IDlPlugin {
  IGameMod * gm_;
  IScenario * sc_;
  DlManager<IGameMod> manag_gm_;
  DlManager<IScenario> manag_sc_;
public:
  PackedPlugin(const std::string &, const std::string &);
  ~PackedPlugin();
};
