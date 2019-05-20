#pragma once
#include "GameState.h"

class Configuration: public GameState
{
public:
	Configuration();
	bool Input(int keyInput) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform, StateManager *stateManager) override;
	void Close() override;
	~Configuration();
};

