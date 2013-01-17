#include "GameplayEngine.h"

Dl::DlManager<PackedPlugin> * GameplayEngine::manager_ = 0;

GameplayEngine::GameplayEngine(std::string path) {
  this->coll_ = new Collider();
  this->quad_ = new QuadTree(1,1,5,5);
  this->manager_ = new Dl::DlManager<PackedPlugin>();
  this->manager_->loadPlugin(path);

  if (this->manager_->isPluginLoaded(path) == true) {
    PackedPlugin * pp_ = this->manager_->getObject("getInstance");
	this->gm_ = pp_->gm_;
	this->sc_ = pp_->sc_;
  }
  else
    std::cerr << "Error on the pack selected." << std::endl;
}

GameplayEngine::~GameplayEngine() {
  delete this->coll_;
  delete this->quad_;
}

void GameplayEngine::handleEvent(/*Event & evt*/) {
  // A coder une fois que la class Event est prete
}

void GameplayEngine::plugEntity(IEntity * tity) {
}

void GameplayEngine::update() {
  //this->quad_->update(this->coll_, this);
}
