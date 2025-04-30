#pragma once
#include "raylib.h"

class Bullet {
public:
	enum class Type {
		Player,
		Enemy
	};
public:
	Bullet() {};

	virtual void draw() = 0;
	virtual void update() = 0;
	
	Vector2 getBulletPositionVector() { return bulletPosition; }

	virtual Type getType() = 0;
	float getBulletY() {
		return bulletPosition.y;
	}

protected:
	Vector2 bulletPosition;
	Type m_type;
};
