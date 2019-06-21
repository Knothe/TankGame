#pragma once
#include "Image.h"
#include "Platform.h"
#include "GameObject.h"
#include "Vector.h"

class EnemyLightT : public GameObject
{
private:
	float angle;
	int energy;

	Image *image;
	Platform *platform;
	float radius;
	Vector position;
	Vector center;
	Vector centerInGame;

public:
	EnemyLightT();
	void Update() override;
	void Draw() override;
	void Init(Platform *platform) override;
	void Init(Platform *platform, int x, int y, float angle);
	float GetRadius();
	int GetPosX();
	int GetPosY();
	Vector GetCenter();
	Vector GetPosition();
	~EnemyLightT();

};

