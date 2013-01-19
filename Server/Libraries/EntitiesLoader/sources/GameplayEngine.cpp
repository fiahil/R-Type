#include "GameplayEngine.h"

Dl::DlManager<PackedPlugin> * GameplayEngine::manager_ = 0;

GameplayEngine::GameplayEngine(std::string path) {
  this->coll_ = new Collider();
  this->quad_ = new QuadTree(800,600,5,5);
  this->manager_ = new Dl::DlManager<PackedPlugin>();
  this->manager_->loadPlugin(path);

  if (this->manager_->isPluginLoaded("Stage_1") == true) {
    PackedPlugin * pp_ = this->manager_->getObject("Stage_1");
	this->gm_ = pp_->gm_;
	this->sc_ = pp_->sc_;
	std::cout << "Success on the recuperation of the pack : " << path << std::endl;
  }
  else
    std::cerr << "Error on the pack selected : " << path << std::endl;
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
  //this->quad_->update(this);
}
