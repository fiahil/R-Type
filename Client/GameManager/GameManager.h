#pragma once

#include	<stack>
#include	"IInput.h"
#include	"IGameWindow.h"
#include	"INetworkManager.hpp"
#include	"Command.h"

typedef int Stage;

class GameManager
{
	IGameWindow			*window_;
	IInput				*input_;
	INetworkManager		*net_;
	std::stack<Stage*>	stack_;

public:
	GameManager(void);
	~GameManager(void);
	void		treatAction(ICommand *);
	ICommand*	getAction();
};

