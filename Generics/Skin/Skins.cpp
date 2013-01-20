

#include	<vector>
#include	"Skin.h"

std::vector<skin>	skinArray;

static skin	initArray[] = {
							{"../Resources/Sprite/r-typesheet42.gif", 5, 5},
							{"../Resources/Sprite/round_bot.gif", 1, 12},
							{"../Resources/Sprite/player_bullet.gif", 1, 2},
							{"../Resources/Sprite/little_death.gif", 1, 6},
							{"../Resources/Sprite/ground_robot.gif", 1, 9},
							{"../Resources/Sprite/ennemy1.gif", 1, 8},
							{"../Resources/Sprite/ennemy_bullet.gif", 1, 8},
							{"../Resources/Sprite/death_bullet_player.gif", 1, 5},
							{"../Resources/Sprite/big_monster.gif", 1, 6},
							{"../Resources/Sprite/big_death.gif", 1, 8}
						};

void	fillArray()
{
	skinArray.push_back(initArray[0]);
	skinArray.push_back(initArray[1]);
	skinArray.push_back(initArray[2]);
	skinArray.push_back(initArray[3]);
	skinArray.push_back(initArray[4]);
	skinArray.push_back(initArray[5]);
	skinArray.push_back(initArray[6]);
	skinArray.push_back(initArray[7]);
	skinArray.push_back(initArray[8]);
	skinArray.push_back(initArray[9]);
}

									
