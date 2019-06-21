#include "Game.h"
#include "Collision.h"
#include <iostream>
#include "Vector.h"
#include <iterator>
#include "StateManager.h"
#include "Ending.h"


void Game::Init(Platform * platform, StateManager *stateManager)
{
	this->stateManager = stateManager;
	bg = new Image();
	bg->LoadImage("../Assets/Images/BattleBg.png");

	this->platform = platform;

	player1 = new Tank(Vector(50, 60), 90, 25);
	player1->Init(platform);
	player1->SetImage(0);
	player1->SetOwnBulletPool(&bulletPool1);
	player1->SetEnemyBulletPool(&bulletPool2);

	player2 = new Tank(Vector(750, 540), 270, 25);
	player2->Init(platform);
	player2->SetImage(1);
	player2->SetOwnBulletPool(&bulletPool2);
	player2->SetEnemyBulletPool(&bulletPool1);


	map = new Map();
	map->Init(platform);

	player1->SetTilePool(map->GetTiles());
	player2->SetTilePool(map->GetTiles());

	player1->SetEnemyTank(player2);
	player2->SetEnemyTank(player1);


	std::cout << "Game Init" << std::endl;
}

bool Game::Input(std::vector<int> *keysDown, std::vector<int> *keysUp)
{
	for (auto num : *keysDown)
	{
		if (num == SDLK_ESCAPE)
		{
			state = false;
		}
	}

	player1->Input(keysDown, keysUp);
	player2->Input(keysDown, keysUp);
	
	return false;
}

void Game::Update()
{
	player1->Update();
	player2->Update();
	CheckBulletCollision(&bulletPool1);
	CheckBulletCollision(&bulletPool2);

	if (!player2->GetState())
	{
		Restart();
 		stateManager->SetState(new Ending(1));
	}
	else if (!player1->GetState())
	{
		Restart();
		stateManager->SetState(new Ending(2));
	}
}

void Game::Restart()
{
	bulletPool1.clear();
	bulletPool2.clear();
	player1->Reset(90);
	player2->Reset(270);
	player1->SetPosition(Vector(50, 60));
	player2->SetPosition(Vector(750, 540));
}

void Game::CheckBulletCollision(std::list<GameObject *> *bulletPool)
{
	std::list<GameObject*>::iterator itTemp;
	std::list<std::list<GameObject*>::iterator> it;
	itTemp = bulletPool->begin();

	for (auto object : *bulletPool)
	{
		object->Update();
		if (!object->GetState())
		{
			it.push_front(itTemp);
		}
		itTemp++;
	}

	for (auto num : it)
	{
		bulletPool->erase(num);
	}
}

void Game::Draw()
{
	
	platform->RenderClear();
	platform->RenderImage(bg, 0, 0);
	player1->Draw();
	player2->Draw();

	for (auto object : bulletPool1)
	{
		object->Draw();
	}
	for (auto object : bulletPool2)
	{
		object->Draw();
	}

	map->Draw();
	platform->RenderPresent();
}

void Game::Close()
{

}

Game::~Game()
{
}
