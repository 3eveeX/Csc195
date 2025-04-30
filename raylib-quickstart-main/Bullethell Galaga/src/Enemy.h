#pragma once
#include "raylib.h"

class Enemy {
public:
	Enemy() = default;
	Enemy(Vector2 playerPosition, int speed);

	void update();
	void draw();

	void setEnemyX(float x);
	void setEnemyY(float y);

	float getEnemyX() { return _enemyPos.x; }
	float getEnemyY() { return _enemyPos.y; }

	int getSpeed() { return _speed; }
	void reverse() {_speed *= -1;}
	
private:
	Vector2 _enemyPos;
	int _speed;
	
};
