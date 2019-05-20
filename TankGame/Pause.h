#pragma once
#include "GameState.h"

class Pause : public GameState
{
public:
	Pause();
	bool Input(int keyInput) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform, StateManager *stateManager) override;
	void Close() override;
	~Pause();
};

