
#pragma once

#include	<map>

#include	"ICommand.h"

struct Move
{
	int x;
	int y;
	int speedx;
	int speedy;
};

struct Fire
{
	int x;
	int y;
	int speedx;
	int speedy;
	int power;
};

template<typename T>
class Command : public ICommand
{
private:
	T cmd_;
	eCommandType type_;

public:
	Command(T cmd, eCommandType type) : cmd_(cmd), type_(type)
	{
	}

	virtual eCommandType getType() const
	{
		return (this->type_);
	}
	
	T& getT()
	{
		return (this->cmd_);
	}
};