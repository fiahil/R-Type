

#include "IGameComponent.h"
#include "GameComponent.h"
#include "sfSpriteSheet.h"

namespace GameResources
{
	IGameComponent* shoot(int x, int y)
	{
		ISpriteSheet	*sprite = new sfSpriteSheet("../Resources/Sprite/ennemy_bullet1.gif", 1, 8);
		sprite->moveTo(x, y);
		IGameComponent	*bullet = new GameComponent(sprite, sprite);

		return bullet;
	}
};