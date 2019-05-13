#pragma once
#include "GameState.h"

class Configuration:GameState
{
public:
	Configuration();
	bool Input(int keyInput) override;
	void Update() override;
	void Draw() override;
	void Init(Platform * platform) override;
	void Close() override;
	~Configuration();
};

