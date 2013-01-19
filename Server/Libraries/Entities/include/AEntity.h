#pragma once

#include <cstdint>
#include "IEntity.h"
#include "IMoveable.h"

class	AEntity : public IEntity
{
protected:
	static uint16_t	currentId_;
/*
	Used by all classes that inherits from this class,
	in order to have a unique ID.
*/

public:
	AEntity();
	virtual ~AEntity();

public:
	virtual uint16_t	getId() const	= 0;
};