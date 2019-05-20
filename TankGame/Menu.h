#pragma once
#include "GameState.h"
#include "Image.h"
#include "StateManager.h"

class Menu : public GameState
{
private:
	Image *background;
	Platform *platform;
	StateManager *stateManager;

public:
	Menu();
	bool Input(int keyInput) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform, StateManager *stateManager) override;
	void Close() override;
	~Menu();
};

