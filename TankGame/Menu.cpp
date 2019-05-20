#include "Game.h"
#include "Menu.h"
#include <iostream>


Menu::Menu()
{
}

bool Menu::Input(int keyInput)
{
	std::cout << "Menu Input";
	if (keyInput == 27) 
	{
		exit(1);
	}
	else 
	{
		stateManager->SetState(new Game());
	}


	return false;
}

void Menu::Update()
{
	std::cout << "Menu Update";
}

void Menu::Draw()
{
	std::cout << "Menu Draw";
	platform->RenderClear();
	platform->RenderImage(background, 0, 0);
	platform->RenderPresent();
}

void Menu::Init(Platform * platform, StateManager *stateManager)
{
	std::cout << "Menu Init";
	this->platform = platform;
	this->stateManager = stateManager;
	background = new Image();
	background->LoadImage("../Assets/Images/background.jpg");
}

void Menu::Close()
{
	std::cout << "Menu close";
}


Menu::~Menu()
{
}
