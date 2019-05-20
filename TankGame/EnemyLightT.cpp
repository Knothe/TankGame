#include "EnemyLightT.h"



EnemyLightT::EnemyLightT()
{
}

void EnemyLightT::Draw()
{
	platform->RenderImage(image, x, y, angle);
}

void EnemyLightT::Init(Platform *platform)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/lightTank.png");
	x = 400;
	y = 200;
	angle = 90;
}

void EnemyLightT::Init(Platform *platform, int x, int y, float angle)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/lightTank.png");
	this->x = x;
	this->y = y;
	this->angle = angle;
}

void EnemyLightT::Input(int input)
{

}

void EnemyLightT::Update()
{

}

EnemyLightT::~EnemyLightT()
{
}
