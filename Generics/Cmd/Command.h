
#pragma once

#include	<map>

#include	"ICommand.h"
#include	"Cmd.h"

template<typename T>
class Command : public ICommand
{
private:
	T cmd_;
	CommandType::eCommandType type_;

public:
	Command(T cmd, CommandType::eCommandType type) : cmd_(cmd), type_(type)
	{
	}

	virtual CommandType::eCommandType getType() const
	{
		return (this->type_);
	}
	
	T& getT()
	{
		return (this->cmd_);
	}
};