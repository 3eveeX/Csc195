#pragma once
#include "raylib.h"

class Player {
public:
	Player() = default;
	Player(Vector2 playerPosition, int size);

	void update();
	void draw();

	void setPlayerX(int x) {
		_playerPos.x = x;
	}
	Rectangle getPlayerBounds() { return playerBounds; }

private:
	Vector2 _playerPos;
	int playerSize;
	Rectangle playerBounds;
};
