#pragma once
#include "GameState.h"
#include "Image.h"
#include "StateManager.h"


class Menu : public GameState
{
private:
	Image *backgrounds[3];
	Image *title;
	Image *start1;
	Image *start2;
	Image *quit1;
	Image *quit2;

	bool option;
	int currentBg;
	Uint16 bgTime;
	Uint32 lastBgTime;
	Platform *platform;
	StateManager *stateManager;

public:
	Menu();
	bool Input(std::vector<int> *keysDown, std::vector<int> *keysUp) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform, StateManager *stateManager) override;
	void Close() override;
	~Menu();
};

