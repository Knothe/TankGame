#include "Game.h"
#include "Menu.h"
#include <iostream>


Menu::Menu()
{
	currentBg = 0;
	lastBgTime = SDL_GetTicks();
	bgTime = 1000;
	option = true;
}

bool Menu::Input(std::vector<int> *keysDown, std::vector<int> *keysUp)
{
	for (auto num : *keysDown)
	{
		std::cout << num << std::endl;
		if (num == SDLK_ESCAPE)
		{
			exit(1);
		}
		else
		{
			if (num == SDLK_DOWN && option)
			{
				option = false;
			}
			else if (num == SDLK_UP && !option)
			{
				option = true;
			}
			else if (num == 13)
			{
				if (option)
				{
					stateManager->SetState(new Game());
				}
				else
				{
					exit(1);
				}
			}
		}
	}

	return false;
}

void Menu::Update()
{
	if (SDL_TICKS_PASSED(SDL_GetTicks(), lastBgTime + bgTime))
	{
		lastBgTime = SDL_GetTicks();
		currentBg += 1;
		if (currentBg > 2)
		{
			currentBg = 0;
		}
	}
}

void Menu::Draw()
{
	platform->RenderClear();
	platform->RenderImage(backgrounds[currentBg], 0, 0);
	platform->RenderImage(title, 144, 50);
	if (option)
	{
		platform->RenderImage(start2, 144, 250);
		platform->RenderImage(quit1, 170, 400);
	}
	else
	{
		platform->RenderImage(start1, 144, 250);
		platform->RenderImage(quit2, 170, 400);
	}
	
	platform->RenderPresent();
}

void Menu::Init(Platform * platform, StateManager *stateManager)
{
	this->platform = platform;
	this->stateManager = stateManager;
	backgrounds[0] = new Image();
	backgrounds[1] = new Image();
	backgrounds[2] = new Image();
	backgrounds[0]->LoadImage("../Assets/Images/background1.png");
	backgrounds[1]->LoadImage("../Assets/Images/background2.png");
	backgrounds[2]->LoadImage("../Assets/Images/background3.png");

	title = new Image();
	start1 = new Image();
	start2 = new Image();
	quit1 = new Image();
	quit2 = new Image();

	title->LoadImage("../Assets/Images/Title.png");
	start1->LoadImage("../Assets/Images/Start1.png");
	start2->LoadImage("../Assets/Images/Start2.png");
	quit1->LoadImage("../Assets/Images/Quit1.png");
	quit2->LoadImage("../Assets/Images/Quit2.png");

}

void Menu::Close()
{
	state = false;
}


Menu::~Menu()
{
}
