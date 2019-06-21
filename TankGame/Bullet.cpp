#include "Bullet.h"
#include "Collision.h"


Bullet::Bullet(Vector vector, float angle, float radius)
{
	state = true;
	int n;
	n = angle / 360;
	this->angle = angle - (360 * n);
	speed = 7;
	this->radius = radius;
	position = vector;
	bounces = 1;
}

void Bullet::Update()
{
	bool col = false;
	position.SetX(position.GetX() + (float)(cos((angle*M_PI) / 180) * speed));
	SetCollider();
	if (Collision())
	{
		col = true;
		if (angle > 0 && angle < 180)
		{
			angle = 180 - angle;
		}
		else if (angle > 180 && angle < 360)
		{
			angle = 540 - angle;
		}
		else if (angle == 0)
		{
			angle = 180;
		}
		else if (angle == 180)
		{
			angle = 0;
		}
	}

	position.SetY(position.GetY() + (float)(sin((angle*M_PI) / 180) * speed));
	SetCollider();
	if (Collision())
	{		
		col = true;
		angle = 360 - angle;
	}

	if (col)
	{
		if (bounces == 0)
		{
			state = false;
		}
		else
		{
			bounces -= 1;
		}
	}
}

void Bullet::Draw()
{
	platform->RenderImage(image, position, angle);
	platform->DrawRect(colPos.GetX(), colPos.GetY(), image->GetHeight(), image->GetHeight());
}

void Bullet::SetCollider()
{
	SetCenterInGame();
	colCenter = centerInGame + Vector((radius*(float)(cos((angle*M_PI) / 180))), (radius*(float)(sin((angle*M_PI) / 180))));
	colPos = colCenter - Vector(image->GetHeight() / 2, image->GetHeight() / 2);
}

void Bullet::SetTilePool(std::vector<Tile *> *tilePool)
{
	this->tilePool = tilePool;
}

bool Bullet::Collision()
{
	for (auto object : *tilePool)
	{
		if (Collision::BoxCollision(colPos, object->GetPosition(),
			Vector(image->GetHeight(), image->GetHeight()),
			Vector(object->GetImage()->GetWidth(), object->GetImage()->GetHeight())))
		{
			return true;

		}
	}
	
	return false;
}

void Bullet::Init(Platform *platform)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/bullet.png");
	center = Vector(image->GetWidth() / 2, image->GetHeight() / 2);
	centerInGame = position + center;
}

Bullet::~Bullet()
{
	delete image;
}
