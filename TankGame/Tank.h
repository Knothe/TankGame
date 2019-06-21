#pragma once
#include "GameObject.h"
#include "Platform.h"
#include "Image.h"
#include "Vector.h"
#include <list>
#include "Bullet.h"
#include <vector>
#include "Tile.h"

class Tank : public GameObject
{
private:
	bool right = false;
	bool left = false;
	bool up = false;
	bool down = false;
	bool shooting;

	Uint32 lastTime;
	Uint16 bulletTime;
	Tank *enemyTank;

	int playerNum;
	float angle;
	float angleSpeed;
	float speed;
	float energy;
	Image *image;
	Platform *platform;
	std::list<GameObject *> *bulletPool1;
	std::list<GameObject *> *bulletPool2;
	std::vector<Tile *> *tilePool;

	void Input1(std::vector<int> *keysDown, std::vector<int> *keysUp);
	void Input2(std::vector<int> *keysDown, std::vector<int> *keysUp);

public:
	Tank(Vector vector, float angle, float radius);
	void Update() override;
	void Input(std::vector<int> *keysDown, std::vector<int> *keysUp);
	
	void Draw() override;
	void Init(Platform *platform) override;
	void SetImage(int playerNum);
	float GetAngle();
	void SetTilePool(std::vector<Tile *> *tilePool);
	bool Collision(int obj);
	void SetEnemyTank(Tank* enemy);
	Image *GetImage();
	void SetOwnBulletPool(std::list<GameObject *> *bulletPool);
	void SetEnemyBulletPool(std::list<GameObject *> *bulletPool);
	void Reset(int angle);
	~Tank();
};

