#pragma once
#include "GameObject.h"
#include <vector>
#include "Tile.h"

class Bullet : public GameObject
{
private:
	int bounces;
	float angle;
	float speed;
	Vector colCenter;
	Vector colPos;
	Image *image;
	Platform *platform;
	std::vector<Tile *> *tilePool;

public:
	Bullet(Vector vector, float angle, float radius);

	void Update() override;
	void Draw() override;
	void Init(Platform *platform) override;
	void SetTilePool(std::vector<Tile *> *tilePool);
	bool Collision();
	void SetCollider();

	
	~Bullet();
};

