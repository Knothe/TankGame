#include "Vector.h"
#include <math.h>
#include <iostream>;


Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
	this->SetSize();
}

Vector::Vector()
{
	x = 0;
	y = 0;
	this->SetSize();
}

void Vector::SetSize()
{
	size = (float)sqrt((x*x) + (y*y));
}

Vector Vector::operator+(Vector vector) 
{
	float x = this->GetX() + vector.GetX();
	float y = this->GetY() + vector.GetY();

	return Vector(x, y);
}

Vector Vector::operator-(Vector vector)
{
	return Vector(this->GetX() - vector.GetX(),
				  this->GetY() - vector.GetY());
}

Vector Vector::operator *(float escalar)
{
	return Vector(escalar * this->GetX(),
				  escalar * this->GetY());
}

float Vector::ProductoPunto(Vector vector)
{
	return ((this->GetX()*vector.GetX()) + (this->GetY()*vector.GetY()));
}

float Vector::DistanciaVector(Vector vector)
{
	float c, a, b;

	a = vector.GetX() - this->GetX();

	b = vector.GetY() - this->GetY();

	c = (float)sqrt((a*a) + (b*b));
	return c;
}

float Vector::GetX()
{
	return x;
}

float Vector::GetY()
{
	return y;
}

float Vector::GetSize()
{
	return size;
}

void Vector::SetX(float x)
{
	this->x = x;
	this->SetSize();

}

void Vector::SetY(float y)
{
	this->y = y;
	this->SetSize();
}

void Vector::Set(float x, float y)
{
	this->x = x;
	this->y = y;
	this->SetSize();
}

Vector::~Vector()
{
}
