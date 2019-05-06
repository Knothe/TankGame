#include "StateManager.h"



StateManager::StateManager()
{
	
}

void StateManager::SetState(GameState *state)
{
	state->Init();
	states.push(state);
}

void StateManager::GameLoop()
{
	while (true)
	{
		auto estado = states.top();
		estado->Input();
		estado->Update();
		estado->Draw();
	}
}

StateManager::~StateManager()
{
}
