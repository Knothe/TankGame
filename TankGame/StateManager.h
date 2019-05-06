#pragma once
#include "GameState.h"
#include <stack>

class StateManager
{
private:
	std::stack<GameState *> states;
public:
	StateManager();
	void SetState(GameState *states);
	void GameLoop();
	~StateManager();
};

