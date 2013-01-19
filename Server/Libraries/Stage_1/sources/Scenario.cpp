#include "Alien1.h"
#include "EntityDecor.h"

#include "Scenario.h"

Scenario::Scenario(float duration) {
  Point			pos(800,300);
  Point			dir(0,300);

  this->duration_ = duration;

  //Beginning of Monster Definition

  Timepoint w1; w1.time_ = 0.f; w1.spawn_ = new EntityDecor(Wall_1,0.5f,Point(0,0),Point(-130,0),HitBox(0,0,130,50)); this->addNewEvent(w1);
  Timepoint w2; w2.time_ = 0.f; w2.spawn_ = new EntityDecor(Wall_1,0.5f,Point(130,0),Point(-130,0),HitBox(130,0,130,50)); this->addNewEvent(w2);
  Timepoint w3; w3.time_ = 0.f; w3.spawn_ = new EntityDecor(Wall_1,0.5f,Point(260,0),Point(-130,0),HitBox(260,0,130,50)); this->addNewEvent(w3);
  Timepoint w4; w4.time_ = 0.f; w4.spawn_ = new EntityDecor(Wall_1,0.5f,Point(390,0),Point(-130,0),HitBox(390,0,130,50)); this->addNewEvent(w4);
  Timepoint w5; w5.time_ = 0.f; w5.spawn_ = new EntityDecor(Wall_1,0.5f,Point(520,0),Point(-130,0),HitBox(520,0,130,50)); this->addNewEvent(w5);
  Timepoint w6; w6.time_ = 0.f; w6.spawn_ = new EntityDecor(Wall_1,0.5f,Point(650,0),Point(-130,0),HitBox(650,0,130,50)); this->addNewEvent(w6);
  Timepoint w7; w7.time_ = 0.f; w7.spawn_ = new EntityDecor(Wall_1,0.5f,Point(780,0),Point(-130,0),HitBox(780,0,130,50)); this->addNewEvent(w7);

  Timepoint w8; w8.time_ = 0.f; w8.spawn_ = new EntityDecor(Wall_1,0.5f,Point(0,550),Point(-130,550),HitBox(0,550,130,50)); this->addNewEvent(w8);
  Timepoint w9; w9.time_ = 0.f; w9.spawn_ = new EntityDecor(Wall_1,0.5f,Point(130,550),Point(-130,550),HitBox(130,550,130,50)); this->addNewEvent(w9);
  Timepoint w10; w10.time_ = 0.f; w10.spawn_ = new EntityDecor(Wall_1,0.5f,Point(260,550),Point(-130,550),HitBox(260,550,130,50)); this->addNewEvent(w10);
  Timepoint w11; w11.time_ = 0.f; w11.spawn_ = new EntityDecor(Wall_1,0.5f,Point(390,550),Point(-130,550),HitBox(390,550,130,50)); this->addNewEvent(w11);
  Timepoint w12; w12.time_ = 0.f; w12.spawn_ = new EntityDecor(Wall_1,0.5f,Point(520,550),Point(-130,550),HitBox(520,550,130,50)); this->addNewEvent(w12);
  Timepoint w13; w13.time_ = 0.f; w13.spawn_ = new EntityDecor(Wall_1,0.5f,Point(650,550),Point(-130,550),HitBox(650,550,130,50)); this->addNewEvent(w13);
  Timepoint w14; w14.time_ = 0.f; w14.spawn_ = new EntityDecor(Wall_1,0.5f,Point(780,550),Point(-130,550),HitBox(780,0,130,50)); this->addNewEvent(w14);

  //End of wall definition -- Begining of Monster definition

  Timepoint tp1; tp1.time_ = 6.f; tp1.spawn_ = new Alien1(Point(800,250),Point(0,350)); this->addNewEvent(tp1);
  Timepoint tp2; tp2.time_ = 7.f; tp1.spawn_ = new Alien1(Point(800,300),Point(0,300)); this->addNewEvent(tp2);
  Timepoint tp3; tp3.time_ = 8.f; tp1.spawn_ = new Alien1(Point(800,350),Point(0,250)); this->addNewEvent(tp3);
  Timepoint tp4; tp4.time_ = 9.f; tp1.spawn_ = new Alien1(Point(800,300),Point(0,400)); this->addNewEvent(tp4);
  Timepoint tp5; tp5.time_ = 10.f; tp1.spawn_ = new Alien1(Point(800,250),Point(0,100)); this->addNewEvent(tp5);
  Timepoint tp6; tp6.time_ = 11.f; tp1.spawn_ = new Alien1(Point(800,350),Point(0,250)); this->addNewEvent(tp6);
  Timepoint tp7; tp7.time_ = 12.f; tp1.spawn_ = new Alien1(Point(800,300),Point(0,350)); this->addNewEvent(tp7);
  Timepoint tp8; tp8.time_ = 13.f; tp1.spawn_ = new Alien1(Point(800,300),Point(0,250)); this->addNewEvent(tp8);
  Timepoint tp9; tp9.time_ = 14.f; tp1.spawn_ = new Alien1(Point(800,250),Point(0,300)); this->addNewEvent(tp9);
  Timepoint tp10; tp10.time_ = 15.f; tp1.spawn_ = new Alien1(Point(800,100),Point(0,400)); this->addNewEvent(tp10);
  Timepoint tp11; tp11.time_ = 16.f; tp1.spawn_ = new Alien1(Point(800,400),Point(0,275)); this->addNewEvent(tp11);
  Timepoint tp12; tp12.time_ = 17.f; tp1.spawn_ = new Alien1(Point(800,500),Point(0,100)); this->addNewEvent(tp12);
  Timepoint tp13; tp13.time_ = 18.f; tp1.spawn_ = new Alien1(Point(800,300),Point(0,100)); this->addNewEvent(tp13);
  Timepoint tp14; tp14.time_ = 19.f; tp1.spawn_ = new Alien1(Point(800,350),Point(0,250)); this->addNewEvent(tp14);
  Timepoint tp15; tp15.time_ = 20.f; tp1.spawn_ = new Alien1(Point(800,250),Point(0,450)); this->addNewEvent(tp15);
  Timepoint tp16; tp16.time_ = 21.f; tp1.spawn_ = new Alien1(Point(800,400),Point(0,150)); this->addNewEvent(tp16);
  Timepoint tp17; tp17.time_ = 22.f; tp1.spawn_ = new Alien1(Point(800,100),Point(0,500)); this->addNewEvent(tp17);
  Timepoint tp18; tp18.time_ = 23.f; tp1.spawn_ = new Alien1(Point(800,150),Point(0,350)); this->addNewEvent(tp18);
  Timepoint tp19; tp19.time_ = 24.f; tp1.spawn_ = new Alien1(Point(800,400),Point(0,75)); this->addNewEvent(tp19);
  Timepoint tp20; tp20.time_ = 25.f; tp1.spawn_ = new Alien1(Point(800,300),Point(0,450)); this->addNewEvent(tp20);
}

Scenario::~Scenario() {

}

IEntity * Scenario::getNextEvent(float atTime, int count) {
  for (std::deque<Timepoint>::iterator it = this->timeline_.begin(); it != this->timeline_.end(); ++it) {
    if ((*it).time_ == atTime)
		if (count == 1)
	      return (*it).spawn_;
		else
		  count--;
  }
  return NULL;
}

void Scenario::addNewEvent(Timepoint Giggowatt) {
  if (Giggowatt.time_ > 0 && Giggowatt.time_ < this->duration_)
    this->timeline_.push_back(Giggowatt);
}

bool Scenario::isOver(float time) {
  if (time < this->duration_)
    return false;
  return true;
}