#include "EnemyLightT.h"



EnemyLightT::EnemyLightT()
{
	position = Vector(400, 200);
	angle = 90;
	radius = 50;
}

void EnemyLightT::Draw()
{
	platform->RenderImage(image, position, angle);
}

void EnemyLightT::Init(Platform *platform)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/lightTank.png");
	
	centerInGame = Vector(image->GetWidth(), image->GetHeight());
	center = position + centerInGame;
}

void EnemyLightT::Init(Platform *platform, int x, int y, float angle)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/lightTank.png");
	position = Vector(x, y);
	this->angle = angle;
	radius = 2;
	centerInGame = Vector(image->GetWidth(), image->GetHeight());
	center = position + centerInGame;
}

float EnemyLightT::GetRadius() 
{
	return radius;
}

int EnemyLightT::GetPosX()
{
	return position.GetX();
}

int EnemyLightT::GetPosY()
{
	return position.GetY();
}

Vector EnemyLightT::GetPosition()
{
	return position;
}

void EnemyLightT::Update()
{
	center = position + centerInGame;
}

Vector EnemyLightT::GetCenter()
{
	return centerInGame;
}

EnemyLightT::~EnemyLightT()
{
}
