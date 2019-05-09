#pragma once
#include "GameState.h"
#include <stack>
#include"Platform.h"

class StateManager
{
private:
	std::stack<GameState *> states;
	Platform *platform;

public:
	StateManager();
	void SetState(GameState *states);
	void GameLoop();
	void ReleaseState();
	~StateManager();
};

