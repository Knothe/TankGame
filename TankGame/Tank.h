#pragma once
#include "GameObject.h"
#include "Platform.h"
#include "Image.h"

class Tank : public GameObject
{
private:
	int x;
	int y;
	float angle;
	float angleSpeed;
	float speed;
	Image *image;
	Platform *platform;

public:
	Tank();
	void Update() override;
	void Input(int input) override;
	void Draw() override;
	void Init(Platform *platform) override;

	~Tank();
};

