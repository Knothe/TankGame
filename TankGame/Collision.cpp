#include "Collision.h"
#include <math.h>

bool Collision::CircleCollision(float r1, float r2, int posx1, int posy1, int posx2, int posy2)
{
	float d = sqrt(((posx2 - posx1)*(posx2 - posx1)) + ((posy2 - posy1)*(posy2 - posy1)));

	if (d >= (r1 + r2)) 
	{
		return false;
	}
	else
	{
		return true;
	}
}

 bool Collision::CircleCollision(float r1, float r2, Vector pos1, Vector pos2)
{
	float d = pos1.DistanciaVector(pos2);

	if (d >= (r1 + r2))
	{
		return false;
	}
	else
	{
		return true;
	}
}

 bool Collision::BoxCollision(Vector pos1, Vector pos2, Vector tam1, Vector tam2)
 {
	 if ((pos2.GetX() >= pos1.GetX() && pos2.GetX() <= pos1.GetX() + tam1.GetX()) ||
		 (pos2.GetX() + tam2.GetX() >= pos1.GetX() &&
			 pos2.GetX() + tam2.GetX() <= pos1.GetX() + tam1.GetX()) ||
			 (pos2.GetX() <= pos1.GetX() && pos2.GetX() + tam2.GetX() >= pos1.GetX() + tam1.GetX()))
	 {
		 if ((pos2.GetY() >= pos1.GetY() && pos2.GetY() <= pos1.GetY() + tam1.GetY()) ||
			 (pos2.GetY() + tam2.GetY() >= pos1.GetY() &&
			 pos2.GetY() + tam2.GetY() <= pos1.GetY() + tam1.GetY()) ||
			(pos2.GetY() <= pos1.GetY() && pos2.GetY() + tam2.GetY() >= pos1.GetY() + tam1.GetY()))
		 {
			 return true;
		 }

	 }
	 return false;
 }