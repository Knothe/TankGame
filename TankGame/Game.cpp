#include "Game.h"
#include <iostream>

Game::Game()
{
}

bool Game::Input(int keyInput)
{
	player->Input(keyInput);
	return false;
}

void Game::Update()
{
	//std::cout << "Game Update";
}

void Game::Draw()
{
	platform->RenderClear();
	player->Draw();
	platform->RenderPresent();
	//std::cout << "Game Draw";
}

void Game::Init(Platform * platform, StateManager *stateManager)
{
	this->platform = platform;
	playerImage = new Image();
	playerImage->LoadImage("../Assets/Images/tank1.png");
	playerX = 50;
	playerY = 50;
	player = new Tank();
	player->Init(platform);
	std::cout << "Game Init";
}

void Game::Close()
{
	std::cout << "Game close";
}

Game::~Game()
{
}
