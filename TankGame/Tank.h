#pragma once
class Tank
{
private:
	int life;
	float moveSpeed;
	float rotationSpeed;
	float stunTime;
	int playerNumber; //?
	//Vector2 Position
	float rotation;
	bool isAlive;
	int points;

public:
	Tank();
	void SetLife(int life);
	int GetLife();
	void SetMoveSpeed(int speed);
	float GetMoveSpeed();
	void SetRotationSpeed(int speed);
	float GetRotationSpeed();
	void SetPoints(int points);
	int GetPoints();
	void SetStunTime(float stunTime);
	float GetStunTime();
	void SetRotation(float rotation);
	float GetRotation();
	void SetAlive(bool isAlive);
	bool GetAlive();

	void Shoot();
	void Move();
	bool GetHit();

	~Tank();
};

