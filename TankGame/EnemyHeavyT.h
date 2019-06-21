#pragma once
#include "GameObject.h"
#include "Platform.h"
#include "Image.h"
#include "Vector.h"
#include <list>

class EnemyHeavyT : public GameObject
{
private:
	float angle;
	int energy;
	std::list<GameObject *> *bulletPool;
	Image *image;
	Platform *platform;
	float radius;
	


public:
	EnemyHeavyT();
	EnemyHeavyT(float x, float y, float angle, float radius);
	void Update() override;
	void Draw() override;
	void Init(Platform *platform) override;
	void Init(Platform *platform, int x, int y, float angle);
	void Collision();
	void SetPool(std::list<GameObject *> *bulletPool);
	~EnemyHeavyT();
};

