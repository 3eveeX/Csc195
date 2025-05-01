#pragma once
#include "Bullet.h"

class EnemyBullet : public Bullet {
public:
	EnemyBullet(Vector2 spawnPos, Type type) {
		bulletPosition = spawnPos;
		m_type = type;
	}

	void draw() override {
		DrawCircleV(bulletPosition, 5, RAYWHITE);
	}
	void update() override {
		bulletPosition.y += 10;
	}
	

	Type getType() override { return Type::Enemy; }
private:

};

