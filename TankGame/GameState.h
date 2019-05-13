#pragma once
#include "Platform.h"

class Platform;

class GameState
{
public:
	virtual bool Input(int keyInput) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Init(Platform * platform) = 0;
	virtual void Close() = 0;
};

