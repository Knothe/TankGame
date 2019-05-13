#include "Menu.h"
#include <iostream>


Menu::Menu()
{
}

bool Menu::Input(int keyInput)
{
	std::cout << "Menu Input";
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

void Menu::Init(Platform * platform)
{
	std::cout << "Menu Init";
	this->platform = platform;
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
