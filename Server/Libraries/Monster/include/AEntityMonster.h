#pragma once

#include <deque>
#include <cstdint>
#include "AEntity.h"
#include "IDrawable.h"
#include "IArmable.h"
#include "ICollidable.h"
#include "IMoveable.h"
#include "IDestroyable.h"
#include "IScriptable.h"

class	AEntityMonster
	:	public AEntity,
		public IDrawable,
		public IArmable,
		public ICollidable,
		public IMoveable,
		public IDestroyable,
		public IScriptable
{
protected:
	int					life_;
	int					power_;
	eMonsterSkin		skin_;
	float				speed_;
	Point				pos_;
	Point				dir_;
	HitBox				hb_;
	uint16_t			id_;
	std::deque<Actions> script_;

protected:
	AEntityMonster(const Point& pos, const Point& dir);
	virtual ~AEntityMonster();

/* Multi herited methods */
protected:	
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
	virtual eAction			getNextAction(float) const;				/* Herited from IScriptable */
};
