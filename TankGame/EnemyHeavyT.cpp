#include "EnemyHeavyT.h"



EnemyHeavyT::EnemyHeavyT()
{
}


void EnemyHeavyT::Update() 
{

}

void EnemyHeavyT::Input(int input)
{

}

void EnemyHeavyT::Draw()
{
	platform->RenderImage(image, x, y);
}

void EnemyHeavyT::Init(Platform *platform)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/heavyTank.png");
	x = 200;
	y = 200;
	angle = 0;
}

void EnemyHeavyT::Init(Platform *platform, int x, int y, float angle)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/heavyTank.png");
	this->x = x;
	this->y = y;
	this->angle = angle;
}

EnemyHeavyT::~EnemyHeavyT()
{
}
