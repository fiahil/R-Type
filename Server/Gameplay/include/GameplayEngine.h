#pragma once

#include "IPlayer.h"
#include "Collider.h"
#include "PackedPlugin.h"
#include "DlManager.h"
#include "IGameMod.h"
#include "IScenario.h"
#include "QuadTree.h"
#include "ICollidable.h"
#include "ICommand.h"
#include <queue>
// Ajouter l'include de la class Event

class GameplayEngine
{
private:
	Collider * coll_;
	QuadTree * quad_;
	static Dl::DlManager<PackedPlugin> * manager_;
	std::deque<IPlayer*>&	players_;
	std::deque<IEntity *>	entities_;

public:
	IGameMod *	gm_;
	IScenario * sc_;

public:
	GameplayEngine(std::string, std::deque<IPlayer*>&);
	~GameplayEngine();

private:
	void	refreshEntitiesPositions();

public:
	void	handleEvent(/*Event*/);
	void	plugEntity(ICollidable *);
	void	update();
	bool	isGameEnded() const;
	bool	isPlayerDead(int) const;
	void	treatPlayersCommands(std::queue<ICommand *>	& cmds);
};
