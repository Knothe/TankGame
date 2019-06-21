#include "Ending.h"


Ending::Ending(int winner)
{
	this->winner = winner;
}

bool Ending::Input(std::vector<int> *keysDown, std::vector<int> *keysUp)
{
	for (auto num : *keysDown)
	{
		if (num == SDLK_RIGHT)
		{
			option = false;
		} else if (num == SDLK_LEFT)
		{
			option = true;
		} else if (num == 13)
		{
			if (option)
			{
				state = false;
			}
			else
			{
				std::exit(1);
			}
		}
	}
	return false;
}

void Ending::Update()
{

}

void Ending::Draw()
{
	//864 / 4 = 216
	//
	platform->RenderClear();
	platform->RenderImage(bg, 0, 0);
	platform->RenderImage(winnerTitle, 42, 0);
	platform->RenderImage(wins, 42, 200);
	if (option)
	{
		platform->RenderImage(replaySelected, 62, 500);
		platform->RenderImage(exit, 496, 500);
	}
	else
	{
		platform->RenderImage(replay, 62, 500);
		platform->RenderImage(exitSelected, 496, 500);
	}

	platform->RenderPresent();
}

void Ending::Init(Platform * platform, StateManager *stateManager)
{
	this->platform = platform;
	this->stateManager = stateManager;
	bg = new Image();
	winnerTitle = new Image();
	wins = new Image();
	exit = new Image();
	exitSelected = new Image();
	replay = new Image();
	replaySelected = new Image();


 	if (winner == 1)
	{
		bg->LoadImage("../Assets/Images/BgPlayer1.png");
		winnerTitle->LoadImage("../Assets/Images/P1.png");
	}
	else if (winner == 2)
	{
		bg->LoadImage("../Assets/Images/BgPlayer2.png");
		winnerTitle->LoadImage("../Assets/Images/P2.png");
	}
	wins->LoadImage("../Assets/Images/Wins.png");
	exit->LoadImage("../Assets/Images/Exit.png");
	exitSelected->LoadImage("../Assets/Images/ExitSelected.png");
	replay->LoadImage("../Assets/Images/Replay.png");
	replaySelected->LoadImage("../Assets/Images/ReplaySelected.png");
	
}

void Ending::Close()
{

}

Ending::~Ending()
{
}
