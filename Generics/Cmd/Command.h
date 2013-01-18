
#pragma once

#include	<map>

#include	"ICommand.h"
#include	"Cmd.h"

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