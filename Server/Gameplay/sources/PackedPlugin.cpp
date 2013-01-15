#include "PackedPlugin.h"

extern "C"
{
  PackedPlugin * entryPoint()
  {
    return this;
  }
}

PackedPlugin::PackedPlugin()
{
}

PackedPlugin::~PackedPlugin()
{
}

IGameMod * PackedPlugin::getGM() const
{
  return this->gm_;
}

IScenario * PackedPlugin::getSC() const
{
  return this->sc_;
}
