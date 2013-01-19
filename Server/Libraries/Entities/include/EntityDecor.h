#pragma once

#include <cstdint>
#include "AEntity.h"
#include "IDrawable.h"
#include "ICollidable.h"
#include "IMoveable.h"

class	EntityDecor
	:	public AEntity,
		public IDrawable,
		public ICollidable,
		public IMoveable
{
private:
	eDecorSkin		skin_;
	float			speed_;
	Point			pos_;
	Point			dir_;
	HitBox			hb_;
	uint16_t		id_;

public:
	EntityDecor(eDecorSkin ds, float speed, const Point& pos,
				const Point& dir, const HitBox& hb);
	virtual ~EntityDecor();

/* Multi herited methods */
public:	
	virtual void			fetchLeftBorder(int& x, int& y) const;	/* Herited from IEntity */
	virtual uint16_t		getId() const;
	virtual int				getSkin() const;						/* Herited from IDrawable */
	virtual const HitBox&	getHitBox() const;						/* Herited from ICollidable */
	virtual const Point&	getPosition() const;					/* Herited from IMoveable */
	virtual const Point&	getDirection() const;
	virtual float			getSpeed() const;
	virtual void			setPosition(int x, int y);
	virtual void			setDirection(int x, int y);
	virtual void			setSpeed(float s);
};