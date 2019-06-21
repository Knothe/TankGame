#pragma once
#include "GameState.h"
#include "Tank.h"
#include "EnemyHeavyT.h"
#include "EnemyLightT.h"
#include "Bullet.h"
#include "Map.h"
#include <list>
#include "Image.h"


class Game : public GameState
{
private:
	Platform *platform;
	Tank *player1;
	Tank *player2;
	Map *map;
	Image *bg;
	std::list<GameObject *> bulletPool1;
	std::list<GameObject *> bulletPool2;
	StateManager *stateManager;
	void CheckBulletCollision(std::list<GameObject *> *bulletPool);

public:
	bool Input(std::vector<int> *keysDown, std::vector<int> *keysUp) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform, StateManager *stateManager) override;
	void Close() override;
	void Restart();
	~Game();
};

