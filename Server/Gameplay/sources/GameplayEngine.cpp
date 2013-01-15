
#include "GameplayEngine.h"

GameplayEngine::GameplayEngine(std::string path) {
  this->coll_ = new Collider();
  this->quad_ = new QuadTree();
  this->manager_ = new DlLoader<PackedPlugin>();
  this->manager->load(path);
  if (this->manager->isPluginLoader(path) == true)
    PackedPlugin pp_ = this->manager->getObject("entryPoint");
  else
    std::cerr << "Error on the pack selected." << std::endl;
  this->gm_ = pp_.getGM();
  this->sc_ = pp_.getSC();
}

GameplayEngine::~GameplayEngine() {
  delete this->coll_;
  delete this->quad_;
}

void GameplayEngine::handleEvent(Event evt) {
  // A coder une fois que la class Event est prete
}

void GameplayEngine::plugEntity(IEntity * tity) {
}

void GameplayEngine::update() {
  this->quad_.update(this->coll_, this);
}
