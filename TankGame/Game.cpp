#include "Game.h"
#include <iostream>

Game::Game()
{
}

bool Game::Input(int keyInput)
{
	std::cout << "Game Input";
	return false;
}

void Game::Update()
{
	std::cout << "Game Update";
}

void Game::Draw()
{
	std::cout << "Game Draw";
}

void Game::Init(Platform * platform)
{
	std::cout << "Game Init";
}

void Game::Close()
{
	std::cout << "Game close";
}

Game::~Game()
{
}
