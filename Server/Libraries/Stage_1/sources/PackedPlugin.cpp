#include "PackedPlugin.h"
#include "Scenario.h"
#include "GameMod.h"

#ifdef WIN32
extern "C" __declspec(dllexport) PackedPlugin * entryPoint() {
	return new PackedPlugin();
}

#else
extern "C" {
PackedPlugin * entryPoint() {
		return new PackedPlugin();
	}
}
#endif

PackedPlugin::PackedPlugin()
{
	this->id_ = "Stage_1";
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

std::string const& PackedPlugin::getId() const{

	return this->id_;
}