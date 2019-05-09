#include <SDL.h>
#include "StateManager.h"
#include "GameState.h"
#include "Menu.h"
#include <iostream>

int main(int argc, char *argv[]) 
{
	
	std::cout << "Si inicia";
	StateManager stateM;
	//stateM.SetState(new Menu());
	stateM.GameLoop();

	return 0;
}