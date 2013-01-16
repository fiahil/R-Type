#include "PackedPlugin.h"
#include "Scenario.h"
#include "GameMod.h"

/*
  Whenever you want to create a new DLL for a game, just specify
  the includes instead of Scenario.h and GameMod.h.
  Also you have to specify the constructors in the PackedPlugin ctor.
*/

extern "C"
{
  PackedPlugin * entryPoint()
  {
    return this;
  }
}

PackedPlugin::PackedPlugin()
{
  this->gm_ = new GameMod();
  this->sc_ = new Scenario();
}

PackedPlugin::~PackedPlugin()
{
  delete this->gm_;
  delete this->sc_;
}

IGameMod * PackedPlugin::getGM() const
{
  return this->gm_;
}

IScenario * PackedPlugin::getSC() const
{
  return this->sc_;
}
