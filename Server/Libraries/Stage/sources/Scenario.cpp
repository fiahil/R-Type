#include "Alien1.h"
#include "EntityDecor.h"

#include "Scenario.h"

// remove
#include <iostream>

Scenario::Scenario()
{

	// Beginning of TOP Wall Definitions
  Timepoint w01(0.0f, new EntityDecor(Wall_1, 0.5f, Point(0,   0), Point(-130, 0), HitBox(0,   0, 130, 50)));	this->addNewEvent(w01);
  Timepoint w02(0.0f, new EntityDecor(Wall_1, 0.5f, Point(130, 0), Point(-130, 0), HitBox(130, 0, 130, 50)));	this->addNewEvent(w02);
  Timepoint w03(0.0f, new EntityDecor(Wall_1, 0.5f, Point(260, 0), Point(-130, 0), HitBox(260, 0, 130, 50)));	this->addNewEvent(w03);
  Timepoint w04(0.0f, new EntityDecor(Wall_1, 0.5f, Point(390, 0), Point(-130, 0), HitBox(390, 0, 130, 50)));	this->addNewEvent(w04);
  Timepoint w05(0.0f, new EntityDecor(Wall_1, 0.5f, Point(520, 0), Point(-130, 0), HitBox(520, 0, 130, 50)));	this->addNewEvent(w05);
  Timepoint w06(0.0f, new EntityDecor(Wall_1, 0.5f, Point(650, 0), Point(-130, 0), HitBox(650, 0, 130, 50)));	this->addNewEvent(w06);
  Timepoint w07(0.0f, new EntityDecor(Wall_1, 0.5f, Point(780, 0), Point(-130, 0), HitBox(780, 0, 130, 50)));	this->addNewEvent(w07);

  // Beginning of BOTTOM Wall Definitions
  Timepoint w08(0.0f, new EntityDecor(Wall_1, 0.5f, Point(0,   550), Point(-130, 550), HitBox(0,   550, 130, 50)));		this->addNewEvent(w08);
  Timepoint w09(0.0f, new EntityDecor(Wall_1, 0.5f, Point(130, 550), Point(-130, 550), HitBox(130, 550, 130, 50)));		this->addNewEvent(w09);
  Timepoint w10(0.0f, new EntityDecor(Wall_1, 0.5f, Point(260, 550), Point(-130, 550), HitBox(260, 550, 130, 50)));		this->addNewEvent(w10);
  Timepoint w11(0.0f, new EntityDecor(Wall_1, 0.5f, Point(390, 550), Point(-130, 550), HitBox(390, 550, 130, 50)));		this->addNewEvent(w11);
  Timepoint w12(0.0f, new EntityDecor(Wall_1, 0.5f, Point(520, 550), Point(-130, 550), HitBox(520, 550, 130, 50)));		this->addNewEvent(w12);
  Timepoint w13(0.0f, new EntityDecor(Wall_1, 0.5f, Point(650, 550), Point(-130, 550), HitBox(650, 550, 130, 50)));		this->addNewEvent(w13);
  Timepoint w14(0.0f, new EntityDecor(Wall_1, 0.5f, Point(780, 550), Point(-130, 550), HitBox(780,   0, 130, 50)));		this->addNewEvent(w14);

  // End of Wall definitions -- Begining of Monster definitions
  Timepoint tp01(6.0f,  new Alien1(Point(800, 250), Point(0, 350)));	this->addNewEvent(tp01);
  Timepoint tp02(7.0f,  new Alien1(Point(800, 300), Point(0, 300)));	this->addNewEvent(tp02);
  Timepoint tp03(8.0f,  new Alien1(Point(800, 350), Point(0, 250)));	this->addNewEvent(tp03);
  Timepoint tp04(9.0f,  new Alien1(Point(800, 300), Point(0, 400)));	this->addNewEvent(tp04);
  Timepoint tp05(10.0f, new Alien1(Point(800, 250), Point(0, 100)));	this->addNewEvent(tp05);
  Timepoint tp06(11.0f, new Alien1(Point(800, 350), Point(0, 250)));	this->addNewEvent(tp06);
  Timepoint tp07(12.0f, new Alien1(Point(800, 300), Point(0, 350)));	this->addNewEvent(tp07);
  Timepoint tp08(13.0f, new Alien1(Point(800, 300), Point(0, 250)));	this->addNewEvent(tp08);
  Timepoint tp09(14.0f, new Alien1(Point(800, 250), Point(0, 300)));	this->addNewEvent(tp09);
  Timepoint tp10(15.0f, new Alien1(Point(800, 100), Point(0, 400)));	this->addNewEvent(tp10);
  Timepoint tp11(16.0f, new Alien1(Point(800, 400), Point(0, 275)));	this->addNewEvent(tp11);
  Timepoint tp12(17.0f, new Alien1(Point(800, 500), Point(0, 100)));	this->addNewEvent(tp12);
  Timepoint tp13(18.0f, new Alien1(Point(800, 300), Point(0, 100)));	this->addNewEvent(tp13);
  Timepoint tp14(19.0f, new Alien1(Point(800, 350), Point(0, 250)));	this->addNewEvent(tp14);
  Timepoint tp15(20.0f, new Alien1(Point(800, 250), Point(0, 450)));	this->addNewEvent(tp15);
  Timepoint tp16(21.0f, new Alien1(Point(800, 400), Point(0, 150)));	this->addNewEvent(tp16);
  Timepoint tp17(22.0f, new Alien1(Point(800, 100), Point(0, 500)));	this->addNewEvent(tp17);
  Timepoint tp18(23.0f, new Alien1(Point(800, 150), Point(0, 350)));	this->addNewEvent(tp18);
  Timepoint tp19(24.0f, new Alien1(Point(800, 400), Point(0, 75)));		this->addNewEvent(tp19);
  Timepoint tp20(25.0f, new Alien1(Point(800, 300), Point(0, 450)));	this->addNewEvent(tp20);

	std::cout << "[Debug]-- Construction Scenario" << std::endl;
}

Scenario::~Scenario()
{
}


bool		Scenario::isOver() const
{
	return this->timeline_.empty();
}


void		Scenario::addNewEvent(Timepoint elem)
{
	if (elem.isValid())
		this->timeline_.push_back(elem);
}


IEntity *	Scenario::getNextEvent(float atTime)
{
	if (this->timeline_.empty())
		return 0;

	Timepoint tmp = this->timeline_.front();

	if (atTime < tmp.time_)
		return 0;
	
	this->timeline_.pop_front();
	return tmp.spawn_;
}
