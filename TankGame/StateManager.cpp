#include "StateManager.h"
#include <iostream>
#include "Platform.h"


StateManager::StateManager()
{
	platform = new Platform("Tank");
}

void StateManager::SetState(GameState *state)
{
	state->Init(platform, this);
	states.push(state);
}

void StateManager::GameLoop()
{
	while (true)
	{	
		try {

			if (states.size() == 0)
			{
				throw std::exception("Error");
			}
			auto estado = states.top();
			platform->CheckEvent(estado, &GameState::Input);
			estado->Update();
			estado->Draw();
			
		}
		catch (...) 
		{
			std::cout << "Critical error Tank is closing";
			break;
		}
		

	}
}

void StateManager::ReleaseState() 
{
	auto state = states.top();
	state->Close();
	states.pop();
}

StateManager::~StateManager()
{
}
