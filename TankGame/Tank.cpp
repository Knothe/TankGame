#include "Tank.h"
#include <iostream>
#include <math.h>
#include "Collision.h"
#include "StateManager.h"

Tank::Tank(Vector vector, float angle, float radius)
{
	this->angle = angle;
	angleSpeed = 2;
	speed = 3;
	this->radius = radius;
	energy = 100;
	position = vector;
	bulletTime = 200;
	shooting = false;
	lastTime = SDL_GetTicks();
}

void Tank::SetOwnBulletPool(std::list<GameObject *> *bulletPool)
{
	this->bulletPool1 = bulletPool;
}

void Tank::SetEnemyBulletPool(std::list<GameObject *> *bulletPool)
{
	this->bulletPool2 = bulletPool;
}

void Tank::SetTilePool(std::vector<Tile *> *tilePool)
{
	this->tilePool = tilePool;
}

void Tank::Update()
{
	if (up)
	{
		position.SetX(position.GetX() + (float)(cos((angle*M_PI) / 180) * speed));
		if (Collision(1))
		{
			position.SetX(position.GetX() - (float)(cos((angle*M_PI) / 180) * speed));
		}

		position.SetY(position.GetY() + (float)(sin((angle*M_PI) / 180) * speed));
		if (Collision(1))
		{
			position.SetY(position.GetY() - (float)(sin((angle*M_PI) / 180) * speed));
		}
	}
	else if (down)
	{
		position.SetX(position.GetX() - (float)(cos((angle*M_PI) / 180) * speed));
		if (Collision(1))
		{
			position.SetX(position.GetX() + (float)(cos((angle*M_PI) / 180) * speed));
		}

		position.SetY(position.GetY() - (float)(sin((angle*M_PI) / 180) * speed));
		if (Collision(1))
		{
			position.SetY(position.GetY() + (float)(sin((angle*M_PI) / 180) * speed));
		}
	}
	if (right)
	{
		angle += angleSpeed;
	}
	else if (left)
	{
		angle -= angleSpeed;
	}

	if (Collision(0))
	{
		energy -= 10;
		if (energy <= 0)
		{
			state = false;
		}
		std::cout << "Golpe" << std::endl;
	}

	SetCenterInGame();
}

void Tank::Input1(std::vector<int> *keysDown, std::vector<int> *keysUp)
{

	for (auto num : *keysDown)
	{
		if (num == SDLK_LEFT)
		{
			left = true;
		}
		if (num == SDLK_RIGHT)
		{
			right = true;
		}
		if (num == SDLK_UP)
		{
			up = true;
		}
		if (num == SDLK_DOWN)
		{
			down = true;
		}
		if (num == SDLK_RCTRL)
		{
			if (shooting)
			{
				shooting = false;
				Bullet* bullet = new Bullet(centerInGame, angle, 12);
				bullet->Init(platform);
				bulletPool1->push_back(bullet);
				bullet->SetTilePool(tilePool);
				lastTime = SDL_GetTicks();
			}
		}
	}
	for (auto num : *keysUp)
	{
		if (num == SDLK_LEFT)
		{
			left = false;
		}
		if (num == SDLK_RIGHT)
		{
			right = false;
		}
		if (num == SDLK_UP)
		{
			up = false;
		}
		if (num == SDLK_DOWN)
		{
			down = false;
		}
	}

}

void Tank::Input2(std::vector<int> *keysDown, std::vector<int> *keysUp)
{
	for (auto num : *keysDown)
	{
		if (num == SDLK_a)
		{
			left = true;
		}
		if (num == SDLK_d)
		{
			right = true;
		}
		if (num == SDLK_w)
		{
			up = true;
		}
		if (num == SDLK_s)
		{
			down = true;
		}
		if (num == SDLK_SPACE)
		{
			if (shooting)
			{
				shooting = false;
				Bullet* bullet = new Bullet(centerInGame, angle, 12);
				bullet->Init(platform);
				bulletPool1->push_back(bullet);
				bullet->SetTilePool(tilePool);
				lastTime = SDL_GetTicks();
			}
		}
	}
	for (auto num : *keysUp)
	{
		if (num == SDLK_a)
		{
			left = false;
		}
		if (num == SDLK_d)
		{
			right = false;
		}
		if (num == SDLK_w)
		{
			up = false;
		}
		if (num == SDLK_s)
		{
			down = false;
		}
	}
}

void Tank::Input(std::vector<int> *keysDown, std::vector<int> *keysUp)
{
 	if (!shooting && SDL_TICKS_PASSED(SDL_GetTicks(),lastTime + bulletTime))
	{
		shooting = true;
	}

	if (playerNum == 0)	
	{
		Input1(keysDown, keysUp);
	}
	else if (playerNum == 1)
	{
		Input2(keysDown, keysUp);
	}

	
}

void Tank::Draw()
{
	if (state) 
	{
		platform->RenderImage(image, position, angle);
		platform->DrawRect((int)position.GetX(), (int)position.GetY(), image->GetWidth(), image->GetHeight());
	}
}

void Tank::Init(Platform *platform)
{
	this->platform = platform;
	image = new Image();
}

void Tank::SetImage(int playerNum)
{
	this->playerNum = playerNum;
	if (playerNum == 0)
	{
		image->LoadImage("../Assets/Images/tank1.png");
	}
	else if (playerNum == 1)
	{
		image->LoadImage("../Assets/Images/tank2.png");
	}
	center = Vector(image->GetWidth() / 2, image->GetHeight() / 2);
	centerInGame = position + center;

}

bool Tank::Collision(int obj)
{
	if (obj == 0)
	{
		for (auto object : *bulletPool2)
		{
			if (Collision::CircleCollision(radius, object->GetRadius(), centerInGame, object->GetCenter()))
			{
				object->SetState(false);
				return true;
			}
		}
	}
	else if (obj == 1)
	{
		for (auto object : *tilePool)
		{
			if (Collision::BoxCollision(position, object->GetPosition(), 
				Vector(image->GetWidth(), image->GetHeight()),
				Vector(object->GetImage()->GetWidth(), object->GetImage()->GetHeight())))
			{
				return true;
			}
		}

		if (Collision::BoxCollision(position, enemyTank->GetPosition(),
			Vector(image->GetWidth(), image->GetHeight()),
			Vector(enemyTank->GetImage()->GetWidth(), enemyTank->GetImage()->GetWidth())))
		{
			return true;
		}
	}

	return false;
	
}

float Tank::GetAngle()
{
	return angle;
}

void Tank::SetEnemyTank(Tank* enemy)
{
	enemyTank = enemy;
}

Image * Tank::GetImage()
{
	return image;
}

void Tank::Reset(int angle)
{
	state = true;
	energy = 100;
	right = false;
	left = false;
	up = false;
	down = false;
	shooting = false;
	this->angle = angle;
}

Tank::~Tank()
{
}
