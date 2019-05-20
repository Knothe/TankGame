#pragma once
#include "GameState.h"
#include "StateManager.h"
#include "Image.h"
#include "Tank.h"
#include "EnemyHeavyT.h"
#include "EnemyLightT.h"

class Game : public GameState
{
private:
	Platform *platform;
	Tank *player;
	EnemyHeavyT *enemy1;
	EnemyLightT *enemy2;
public:
	Game();
	bool Input(int keyInput) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform, StateManager *stateManager) override;
	void Close() override;
	~Game();
};

