#include "GameplayEngine.h"

GameplayEngine::GameplayEngine() {
  this->coll_ = new Collider();
  this->quad_ = new QuadTree();
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
