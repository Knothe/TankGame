#pragma once
#include "Platform.h"

class GameObject
{
protected:
	bool state = true;
	Vector position;
	float radius;
	Vector center;
	Vector centerInGame;

public:
	virtual void Draw() = 0;
	virtual void Init(Platform *platform) = 0;
	virtual void Update() = 0;
	float GetRadius();
	int GetPosX();
	int GetPosY();
	Vector GetPosition();
	void SetCenterInGame();
	void SetState(bool estado);
	bool GetState();
	Vector GetCenter();
	void SetPosition(Vector position);
};

