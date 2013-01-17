#pragma once

#include <deque>

#include "IEntity.h"
#include "IDrawable.h"
#include "IArmable.h"
#include "ICollidable.h"
#include "IMoveable.h"
#include "IDestroyable.h"
#include "IScriptable.h"

class	AMonster :	public IEntity,
					public IDrawable,
					public IArmable,
					public ICollidable,
					public IMoveable,
					public IDestroyable,
					public IScriptable
{
protected:
	int		life_;
	int		power_;
	eSkin	skin_;					/* [eSkin]	 : IDrawable.h */
	float	speed_;
	Point	pos_;					/* [Point]   : IEntity.h */
	Point	dir_;
	HitBox	hb_;					/* [HitBox]  : ICollidable.h */
	std::deque<Actions> script_;	/* [Actions] : IScriptable.h */

protected:
	AMonster(const Point& pos, const Point& dir);
	virtual ~AMonster();

/* Multi herited methods */
protected:	
	virtual void			fetchLeftBorder(int& x, int& y) const;	/* Herited from IEntity */
	virtual int				getSkin() const;						/* Herited from IDrawable */
	virtual int				getPower() const;						/* Herited from IArmable */
	virtual const HitBox&	getHitBox() const;						/* Herited from ICollidable */
	virtual const Point&	getDirection() const;					/* Herited from IMoveable */
	virtual float			getSpeed() const;
	virtual void			destroy();								/* Herited from IDestroyable */
	virtual int				getLife() const;
	virtual	void			subLife(int dmg);
	virtual eAction			getNextAction(float) const;				/* Herited from IScriptable */
};
