#pragma once
#include "Image.h"
#include "Platform.h"
#include "GameObject.h"

class EnemyLightT : public GameObject
{
private:
	int x;
	int y;
	float angle;
	Image *image;
	Platform *platform;

public:
	EnemyLightT();

	void Update() override;
	void Input(int input) override;
	void Draw() override;
	void Init(Platform *platform) override;
	void Init(Platform *platform, int x, int y, float angle);
	~EnemyLightT();

};

