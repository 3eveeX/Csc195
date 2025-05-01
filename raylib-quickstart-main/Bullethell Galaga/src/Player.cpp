#include "Player.h"


Player::Player(Vector2 playerPosition, int size)
{
	_playerPos = playerPosition;
	playerSize = size;
	playerBounds = Rectangle{ _playerPos.x, _playerPos.y, playerSize / 2.0f, playerSize / 2.0f };
}

void Player::update()
{
	 playerBounds = Rectangle{ _playerPos.x, _playerPos.y-20, playerSize / 2.0f, playerSize / 2.0f };
}



void Player::draw()
{
	DrawPoly(_playerPos, 3, playerSize, -90, YELLOW);
}