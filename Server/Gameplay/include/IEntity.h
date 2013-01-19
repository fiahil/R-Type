#pragma once

#include <cstdint>

class	IEntity
{
public:
	virtual ~IEntity() {}

public:
	virtual uint16_t	getId() const	= 0;
};