#pragma once
#include "Platform.h"

class Platform;
class StateManager;

class GameState
{
public:
	virtual bool Input(int keyInput) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Init(Platform * platform, StateManager *stateManager) = 0;
	virtual void Close() = 0;
};

