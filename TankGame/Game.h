#pragma once
#include "GameState.h"
#include "StateManager.h"
#include "Image.h"
#include "Tank.h"

class Game : public GameState
{
private:
	Platform *platform;
	Image *playerImage;
	int playerX;
	int playerY;
	Tank *player;
public:
	Game();
	bool Input(int keyInput) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform, StateManager *stateManager) override;
	void Close() override;
	~Game();
};

