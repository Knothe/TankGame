#pragma once
#include "GameState.h"
#include "Image.h"


class Ending : public GameState
{
private:
	Platform *platform;
	StateManager *stateManager;
	Image *bg;
	Image *winnerTitle;
	Image *wins;
	Image *exit;
	Image *exitSelected;
	Image *replay;
	Image *replaySelected;
	int winner;
	bool option = true;

public:
	Ending(int winner);

	bool Input(std::vector<int> *keysDown, std::vector<int> *keysUp) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform, StateManager *stateManager) override;
	void Close() override;


	~Ending();
};

