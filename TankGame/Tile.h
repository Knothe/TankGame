#pragma once
#include "GameObject.h"
#include "Vector.h"

class Tile : public GameObject
{
private:
	Image *image;
	Platform *platform;
	Vector center;

public:
	Tile(Vector vector, float radius);
	void Update() override;
	void Draw() override;
	void Init(Platform *platform) override;
	Vector GetCenter();
	Image* GetImage();
	~Tile();
};

