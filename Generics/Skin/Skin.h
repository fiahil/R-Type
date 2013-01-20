#pragma once 

#include	<vector>

struct skin
{
	char	filePath[128];
	int		anim;
	int		frame;
};

void	fillArray();

extern std::vector<skin>	skinArray;
