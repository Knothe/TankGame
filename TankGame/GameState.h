#pragma once
#include "Platform.h"
#include "SDL.h"
#include <vector>

class Platform;
class StateManager;

class GameState
{
protected:
	bool state = true;
public:
	virtual bool Input(std::vector<int> *keysDown, std::vector<int> *keysUp) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Init(Platform * platform, StateManager *stateManager) = 0;
	virtual void Close() = 0;
};

