#pragma once

#include <string>

class IGameWindow
{

public:
	virtual void	getWindowSize(int&, int&) = 0;
	virtual void	gainFocus() = 0;
	virtual void	lostFocus() = 0;
	virtual void	setTitle(std::string const&) = 0;
	virtual void	setCursorVisible(bool) = 0;

	IGameWindow(void);
	virtual	~IGameWindow(void);
};
