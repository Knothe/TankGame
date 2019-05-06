#include "Game.h"
#include <iostream>

Game::Game()
{
}

void Game::Input()
{
	std::cout << "Game Input";
}

void Game::Update()
{
	std::cout << "Game Update";
}

void Game::Draw()
{
	std::cout << "Game Draw";
}

void Game::Init()
{
	std::cout << "Game Init";
}

Game::~Game()
{
}
