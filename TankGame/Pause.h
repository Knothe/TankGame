#pragma once
#include "GameState.h"

class Pause : GameState
{
public:
	Pause();
	bool Input(int keyInput) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform) override;
	void Close() override;
	~Pause();
};

