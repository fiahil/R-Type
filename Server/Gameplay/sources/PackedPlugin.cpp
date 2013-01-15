#include "PackedPlugin.h"

PackedPlugin::PackedPlugin(const std::string & gm_path, const std::string & sc_path)
{
  this->manag_gm_ = new DlManager<IGameMod>();
  this->manag_sc_ = new DlManager<IScenario>();
  this->gm_ = this->manag_gm_->load(gm_path);
  this->sc_ = this->manag_sc_->load(sc_path);
}

PackedPlugin::~PackedPlugin()
{

}
