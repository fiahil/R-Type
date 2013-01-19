#pragma once

#include <cstdint>
#include "AEntity.h"
#include "IDrawable.h"
#include "IArmable.h"
#include "ICollidable.h"
#include "IMoveable.h"
#include "IDestroyable.h"

class	EntityWeapon
	:	public AEntity,
		public IDrawable,
		public IArmable,
		public ICollidable,
		public IMoveable,
		public IDestroyable
{
private:
	int				life_;
	int				power_;
	eWeaponSkin		skin_;
	float			speed_;
	Point			pos_;
	Point			dir_;
	HitBox			hb_;
	uint16_t		id_;

public:
	EntityWeapon(int life, int power, eWeaponSkin skin, float speed,
				const Point& pos, const Point& dir, const HitBox& hb);
	virtual ~EntityWeapon();

/* Multi herited methods */
public:
	virtual void			fetchLeftBorder(int& x, int& y) const;	/* Herited from IEntity */
	virtual uint16_t		getId() const;
	virtual int				getSkin() const;						/* Herited from IDrawable */
	virtual int				getPower() const;						/* Herited from IArmable */
	virtual const HitBox&	getHitBox() const;						/* Herited from ICollidable */
	virtual const Point&	getPosition() const;					/* Herited from IMoveable */
	virtual const Point&	getDirection() const;
	virtual float			getSpeed() const;
	virtual void			setPosition(int x, int y);
	virtual void			setDirection(int x, int y);
	virtual void			setSpeed(float s);
	virtual void			destroy();								/* Herited from IDestroyable */
	virtual int				getLife() const;
	virtual	void			subLife(int dmg);
};
