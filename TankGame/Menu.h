#pragma once
#include "GameState.h"

class Menu : public GameState
{
public:
	Menu();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	~Menu();
};
