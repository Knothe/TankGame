#pragma once
#include "GameState.h"

class Pause : GameState
{
public:
	Pause();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
	~Pause();
};

