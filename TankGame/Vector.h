#pragma once
class Vector
{
private:
	float x;
	float y;
	float size;
	void SetSize();

public:
	Vector(float x, float y);
	Vector();

	Vector operator +(Vector vector);
	Vector operator -(Vector vector);
	Vector operator *(float escalar); //Producto escalar

	float ProductoPunto(Vector vector);
	float DistanciaVector(Vector vector);

	float GetX();
	float GetY();
	float GetSize();

	void SetX(float x);
	void SetY(float y);
	void Set(float x, float y);

	~Vector();
};

