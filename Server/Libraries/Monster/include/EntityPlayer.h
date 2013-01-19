#pragma once

#include <cstdint>
#include "AEntity.h"
#include "IDrawable.h"
#include "IArmable.h"
#include "ICollidable.h"
#include "IMoveable.h"
#include "IDestroyable.h"
#include "IPlayable.h"

class	EntityPlayer
	:	public AEntity,
		public IDrawable,
		public IArmable,
		public ICollidable,
		public IDestroyable,
		public IPlayable
{
private:
	int				life_;
	int				power_;
	ePlayerSkin		skin_;
	float			speed_;
	Point			pos_;
	Point			dir_;
	HitBox			hb_;
	uint16_t		id_;

public:
	EntityPlayer(int life, int power, ePlayerSkin skin, float speed,
				const Point& pos, const Point& dir, const HitBox& hb);
	virtual ~EntityPlayer();

/* Multi herited methods */
public:	
	virtual void			fetchLeftBorder(int& x, int& y) const;	/* Herited from IEntity */
	virtual uint16_t		getId() const;
	virtual int				getSkin() const;						/* Herited from IDrawable */
	virtual int				getPower() const;						/* Herited from IArmable */
	virtual const HitBox&	getHitBox() const;						/* Herited from ICollidable */
	virtual void			destroy();								/* Herited from IDestroyable */
	virtual int				getLife() const;
	virtual	void			subLife(int dmg);
	virtual const Point&	getPosition() const;					/* Herited from IPlayable */
	virtual void			setPosition(int x, int y);
};
