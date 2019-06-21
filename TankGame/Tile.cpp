#include "Tile.h"



Tile::Tile(Vector vector, float radius)
{
	position = vector;
	this->radius = radius;
}

void Tile::Init(Platform *platform)
{
	this->platform = platform;
	image = new Image();
	image->LoadImage("../Assets/Images/Tile.png");
	center = position + Vector(image->GetWidth() / 2, image->GetWidth() / 2);
}

Image* Tile::GetImage()
{
	return image;
}

void Tile::Update()
{

}

void Tile::Draw()
{
	platform->RenderImage(image, position);
	platform->DrawRect(position.GetX(), position.GetY(), image->GetWidth(), image->GetHeight());
}

Vector Tile::GetCenter()
{
	return center;
}

Tile::~Tile()
{
}
