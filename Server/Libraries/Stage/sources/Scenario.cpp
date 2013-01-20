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
 
  Timepoint tp21(26.0f, new Alien1(Point(800, 500), Point(0, 100)));	this->addNewEvent(tp21);
  Timepoint tp22(26.75f, new Alien1(Point(800, 300), Point(0, 100)));	this->addNewEvent(tp22);
  Timepoint tp23(27.5f, new Alien1(Point(800, 350), Point(0, 250)));	this->addNewEvent(tp23);
  Timepoint tp24(28.25f, new Alien1(Point(800, 250), Point(0, 450)));	this->addNewEvent(tp24);
  Timepoint tp25(29.0f, new Alien1(Point(800, 250), Point(0, 450)));	this->addNewEvent(tp25);
  Timepoint tp26(29.75f, new Alien1(Point(800, 400), Point(0, 150)));	this->addNewEvent(tp26);
  Timepoint tp27(30.5f, new Alien1(Point(800, 100), Point(0, 500)));	this->addNewEvent(tp27);
  Timepoint tp28(31.25f, new Alien1(Point(800, 150), Point(0, 350)));	this->addNewEvent(tp28);
  Timepoint tp29(32.0f, new Alien1(Point(800, 400), Point(0, 75)));		this->addNewEvent(tp29);
  Timepoint tp30(32.75f, new Alien1(Point(800, 300), Point(0, 450)));	this->addNewEvent(tp30);
  Timepoint tp31(33.5f,  new Alien1(Point(800, 250), Point(0, 350)));	this->addNewEvent(tp31);
  Timepoint tp32(34.25f,  new Alien1(Point(800, 300), Point(0, 300)));	this->addNewEvent(tp32);
  Timepoint tp33(35.0f,  new Alien1(Point(800, 350), Point(0, 250)));	this->addNewEvent(tp33);
  Timepoint tp34(35.75f,  new Alien1(Point(800, 300), Point(0, 400)));	this->addNewEvent(tp34);
  Timepoint tp35(36.5f, new Alien1(Point(800, 250), Point(0, 100)));	this->addNewEvent(tp35);
  Timepoint tp36(37.25f, new Alien1(Point(800, 350), Point(0, 250)));	this->addNewEvent(tp36);
  Timepoint tp37(38.0f, new Alien1(Point(800, 300), Point(0, 350)));	this->addNewEvent(tp37);
  Timepoint tp38(38.75f, new Alien1(Point(800, 300), Point(0, 250)));	this->addNewEvent(tp38);
  Timepoint tp39(39.5f, new Alien1(Point(800, 250), Point(0, 300)));	this->addNewEvent(tp39);
  Timepoint tp40(40.25f, new Alien1(Point(800, 100), Point(0, 400)));	this->addNewEvent(tp40);
  Timepoint tp41(41.0f, new Alien1(Point(800, 400), Point(0, 275)));	this->addNewEvent(tp41);
  Timepoint tp42(41.75f, new Alien1(Point(800, 500), Point(0, 100)));	this->addNewEvent(tp42);
  Timepoint tp43(42.5f, new Alien1(Point(800, 300), Point(0, 100)));	this->addNewEvent(tp43);
  Timepoint tp44(43.25f, new Alien1(Point(800, 350), Point(0, 250)));	this->addNewEvent(tp44);
  Timepoint tp45(44.0f, new Alien1(Point(800, 250), Point(0, 450)));	this->addNewEvent(tp45);
  Timepoint tp46(44.75f, new Alien1(Point(800, 400), Point(0, 137)));	this->addNewEvent(tp46);
  Timepoint tp47(45.5f, new Alien1(Point(800, 150), Point(0, 197)));	this->addNewEvent(tp47);
  Timepoint tp48(46.25f, new Alien1(Point(800, 125), Point(0, 465)));	this->addNewEvent(tp48);
  Timepoint tp49(47.0f, new Alien1(Point(800, 340), Point(0, 432)));	this->addNewEvent(tp49);
  Timepoint tp50(47.75f, new Alien1(Point(800, 520), Point(0, 462)));	this->addNewEvent(tp50);
  Timepoint tp51(48.5f, new Alien1(Point(800, 85), Point(0, 145)));		this->addNewEvent(tp51);
  Timepoint tp52(49.25f, new Alien1(Point(800, 250), Point(0, 282)));	this->addNewEvent(tp52);
  Timepoint tp53(50.0f, new Alien1(Point(800, 300), Point(0, 323)));	this->addNewEvent(tp53);

  Timepoint tp54(50.5f, new Alien1(Point(800, 100), Point(0, 110)));	this->addNewEvent(tp54);
  Timepoint tp55(51.0f, new Alien1(Point(800, 400), Point(0, 507)));	this->addNewEvent(tp55);
  Timepoint tp56(51.5f, new Alien1(Point(800, 450), Point(0, 186)));	this->addNewEvent(tp56);
  Timepoint tp57(52.0f, new Alien1(Point(800, 500), Point(0, 285)));	this->addNewEvent(tp57);
  Timepoint tp58(52.5f, new Alien1(Point(800, 125), Point(0, 71)));		this->addNewEvent(tp58);
  Timepoint tp59(53.0f, new Alien1(Point(800, 150), Point(0, 424)));	this->addNewEvent(tp59);
  Timepoint tp60(53.5f, new Alien1(Point(800, 300), Point(0, 290)));	this->addNewEvent(tp60);
  Timepoint tp61(54.0f, new Alien1(Point(800, 500), Point(0, 409)));	this->addNewEvent(tp61);
  Timepoint tp62(54.5f, new Alien1(Point(800, 550), Point(0, 100)));	this->addNewEvent(tp62);
  Timepoint tp63(55.0f, new Alien1(Point(800, 400), Point(0, 467)));	this->addNewEvent(tp63);
  Timepoint tp64(55.5f, new Alien1(Point(800, 320), Point(0, 62)));		this->addNewEvent(tp64);
  Timepoint tp65(56.0f, new Alien1(Point(800, 300), Point(0, 499)));	this->addNewEvent(tp65);
  Timepoint tp66(56.5f, new Alien1(Point(800, 550), Point(0, 404)));	this->addNewEvent(tp66);
  Timepoint tp67(57.0f, new Alien1(Point(800, 125), Point(0, 449)));	this->addNewEvent(tp67);
  Timepoint tp68(57.5f, new Alien1(Point(800, 400), Point(0, 441)));	this->addNewEvent(tp68);
  Timepoint tp69(58.0f, new Alien1(Point(800, 150), Point(0, 93)));		this->addNewEvent(tp69);
  Timepoint tp70(58.5f, new Alien1(Point(800, 550), Point(0, 348)));	this->addNewEvent(tp70);
  Timepoint tp71(59.0f, new Alien1(Point(800, 425), Point(0, 197)));	this->addNewEvent(tp71);
  Timepoint tp72(59.5f, new Alien1(Point(800, 300), Point(0, 471)));	this->addNewEvent(tp72);
  Timepoint tp73(60.0f, new Alien1(Point(800, 325), Point(0, 355)));	this->addNewEvent(tp73);
  Timepoint tp74(60.5f, new Alien1(Point(800, 450), Point(0, 381)));	this->addNewEvent(tp74);
  Timepoint tp75(61.0f, new Alien1(Point(800, 80), Point(0, 347)));		this->addNewEvent(tp75);
  Timepoint tp76(61.5f, new Alien1(Point(800, 50), Point(0, 152)));		this->addNewEvent(tp76);
  Timepoint tp77(62.0f, new Alien1(Point(800, 300), Point(0, 538)));	this->addNewEvent(tp77);
  Timepoint tp78(62.5f, new Alien1(Point(800, 320), Point(0, 302)));	this->addNewEvent(tp78);
  Timepoint tp79(63.0f, new Alien1(Point(800, 475), Point(0, 52)));		this->addNewEvent(tp79);
  Timepoint tp80(63.5f, new Alien1(Point(800, 550), Point(0, 355)));	this->addNewEvent(tp80);
  Timepoint tp81(64.0f, new Alien1(Point(800, 275), Point(0, 168)));	this->addNewEvent(tp81);
  Timepoint tp82(64.5f, new Alien1(Point(800, 400), Point(0, 344)));	this->addNewEvent(tp82);
  Timepoint tp83(65.0f, new Alien1(Point(800, 300), Point(0, 411)));	this->addNewEvent(tp83);
  Timepoint tp84(65.5f, new Alien1(Point(800, 550), Point(0, 371)));	this->addNewEvent(tp84);
  Timepoint tp85(66.0f, new Alien1(Point(800, 310), Point(0, 112)));	this->addNewEvent(tp85);
  Timepoint tp86(66.5f, new Alien1(Point(800, 420), Point(0, 349)));	this->addNewEvent(tp86);
  Timepoint tp87(67.0f, new Alien1(Point(800, 180), Point(0, 501)));	this->addNewEvent(tp87);
  Timepoint tp88(67.5f, new Alien1(Point(800, 512), Point(0, 52)));		this->addNewEvent(tp88);
  Timepoint tp89(68.0f, new Alien1(Point(800, 126), Point(0, 95)));		this->addNewEvent(tp89);
  Timepoint tp90(68.5f, new Alien1(Point(800, 369), Point(0, 271)));	this->addNewEvent(tp90);
  Timepoint tp91(69.0f, new Alien1(Point(800, 170), Point(0, 70)));		this->addNewEvent(tp91);
  Timepoint tp92(69.5f, new Alien1(Point(800, 385), Point(0, 532)));	this->addNewEvent(tp92);
  Timepoint tp93(70.0f, new Alien1(Point(800, 470), Point(0, 339)));	this->addNewEvent(tp93);
  Timepoint tp94(70.5f, new Alien1(Point(800, 120), Point(0, 456)));	this->addNewEvent(tp94);
  Timepoint tp95(71.0f, new Alien1(Point(800, 371), Point(0, 158)));	this->addNewEvent(tp95);
  Timepoint tp96(71.5f, new Alien1(Point(800, 98), Point(0, 447)));		this->addNewEvent(tp96);
  Timepoint tp97(72.0f, new Alien1(Point(800, 405), Point(0, 343)));	this->addNewEvent(tp97);
  Timepoint tp98(72.5f, new Alien1(Point(800, 214), Point(0, 127)));	this->addNewEvent(tp98);
  Timepoint tp99(73.0f, new Alien1(Point(800, 298), Point(0, 391)));	this->addNewEvent(tp99);
  Timepoint tp100(73.5f, new Alien1(Point(800, 123), Point(0, 150)));	this->addNewEvent(tp100);

  
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
