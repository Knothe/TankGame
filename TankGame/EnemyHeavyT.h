#pragma once
#include "GameObject.h"
#include "Platform.h"
#include "Image.h"

class EnemyHeavyT : public GameObject
{
private:
	int x;
	int y;
	float angle;
	Image *image;
	Platform *platform;

public:
	EnemyHeavyT();

	void Update() override;
	void Input(int input) override;
	void Draw() override;
	void Init(Platform *platform) override;
	void Init(Platform *platform, int x, int y, float angle);
	~EnemyHeavyT();
};

