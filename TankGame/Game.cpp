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
	enemy1->Draw();
	enemy2->Draw();
	platform->RenderPresent();
	//std::cout << "Game Draw";
}

void Game::Init(Platform * platform, StateManager *stateManager)
{
	this->platform = platform;
	player = new Tank();
	player->Init(platform);

	enemy1 = new EnemyHeavyT();
	enemy1->Init(platform);

	enemy2 = new EnemyLightT();
	enemy2->Init(platform, 400, 200, 90);

	std::cout << "Game Init";
}

void Game::Close()
{
	std::cout << "Game close";
}

Game::~Game()
{
}
