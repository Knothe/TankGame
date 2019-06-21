#include "EnemyHeavyT.h"
#include "Collision.h"


EnemyHeavyT::EnemyHeavyT()
{
	position = Vector(200, 200);
	angle = 0;
	radius = 60;
	energy = 100;
}

EnemyHeavyT::EnemyHeavyT(float x, float y, float angle, float radius)
{
	position = Vector(200, 200);
	this->angle = angle;
	this->radius = radius;
}

void EnemyHeavyT::Update() 
{
	SetCenterInGame();
	Collision();
}

void EnemyHeavyT::SetPool(std::list<GameObject *> *bulletPool)
{
	this->bulletPool = bulletPool;
}

void EnemyHeavyT::Collision()
{
	for (auto object : *bulletPool)
	{
		if (Collision::CircleCollision(radius, object->GetRadius(), centerInGame, object->GetCenter()))
		{
			std::cout << "Pego la bala" << std::endl;
		}
	}
}

void EnemyHeavyT::Draw()
{
	if(energy > 0)
		platform->RenderImage(image, position);
}

void EnemyHeavyT::Init(Platform *platform)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/heavyTank.png");
	center = Vector(image->GetWidth() / 2, image->GetHeight()/ 2);
	SetCenterInGame();
}

void EnemyHeavyT::Init(Platform *platform, int x, int y, float angle)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/heavyTank.png");
	position = Vector(x, y);
	this->angle = angle;
}

EnemyHeavyT::~EnemyHeavyT()
{
}
