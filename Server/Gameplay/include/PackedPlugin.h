#pragma once

#include "IDlPlugin.h"
#include "IGameMod.h"
#include "IScenario.h"

class PackedPlugin : public Dl::IDlPlugin {
  IGameMod * gm_;
  IScenario * sc_;
  std::string id_;
public:
  PackedPlugin();
  ~PackedPlugin();
  IGameMod * getGM() const;
  IScenario * getSC() const;
  std::string const& getId() const;
};
