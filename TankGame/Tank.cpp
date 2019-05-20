#include "Tank.h"
#include <iostream>
#include <math.h>

Tank::Tank()
{
}

void Tank::Update()
{
	
}

void Tank::Input(int input)
{
	std::cout << input << std::endl;
	if (input == 1073741903) 
	{
		angle+=angleSpeed;
	}
	else if (input == 1073741904) 
	{
		angle-=angleSpeed;
	}
	else if (input == 1073741905) 
	{
		x -= (int)(sin(angle*M_PI / 180) * speed);
		y += (int)(cos(angle*M_PI / 180) * speed);
	}
 	else if (input == 1073741906) 
	{
		x += (int)(sin(angle*M_PI / 180) * speed);
		y -= (int)(cos(angle*M_PI / 180) * speed);
	}
}

void Tank::Draw()
{
	platform->RenderImage(image, x, y, angle);
}

void Tank::Init(Platform *platform)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/tank1.png");
	x = 100;
	y = 100;
	angle = 0;
	angleSpeed = 10;
	speed = 5;
}


Tank::~Tank()
{
}
