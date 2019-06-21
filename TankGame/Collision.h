#pragma once
#include "Vector.h"

class Collision
{
public:
	static bool CircleCollision(float r1, float r2, int posx1, int posy1, int posx2, int posy2);
	static bool CircleCollision(float r1, float r2, Vector pos1, Vector pos2);
	static bool BoxCollision(Vector pos1, Vector pos2, Vector tam1, Vector tam2);
};

