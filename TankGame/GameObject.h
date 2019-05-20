#pragma once
#include "Platform.h"

class GameObject
{
public:
	virtual void Update() = 0;
	virtual void Input(int input) = 0;
	virtual void Draw() = 0;
	virtual void Init(Platform *platform) = 0;
};

