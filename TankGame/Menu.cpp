#include "Menu.h"
#include <iostream>


Menu::Menu()
{
}

void Menu::Input()
{
	std::cout << "Menu Input";
}

void Menu::Update()
{
	std::cout << "Menu Update";
}

void Menu::Draw()
{
	std::cout << "Menu Draw";
}

void Menu::Init()
{
	std::cout << "Menu Init";
}

void Menu::Close()
{
	std::cout << "Menu close";
}


Menu::~Menu()
{
}
