#pragma once

/* #include <SFML/Graphics.h> */

enum	ePlayerSkin
{
	Player_1,
	Player_2,
	Player_3,
	Player_4,
	ErrorPlayerSkin
};

enum eWeaponSkin
{
	Weapon_1,
	Weapon_2,
	Weapon_3,
	ErrorWeaponSkin
};

enum	eDecorSkin
{
	Wall_1,
	Wall_2,
	Wall_3,
	ErrorDecorSkin
};


enum	eMonsterSkin
{
/* Lvl 1*/
	Alien_1,		// small red
	Alien_2,		// small glod
	Alien_3,		// green
	Alien_4,		// steel
	Alien_5,		// orange 
	Apu_1,			// orange
	Apu_2,			// blue
	Ball_1,			// white
	Disc_1,			// grey-orange
	Disc_2,			// blue-orange
	Turret_1,		// small white-orange
	BossLvl_1,		// Boss lvl 1
/* Others */
	ErrorMonsterSkin
};

class IDrawable
{
public:
  virtual ~IDrawable(void) {}
  virtual int getSkin() const	= 0;
};
