#include "Player.h"

Player::Player(Vector2 playerPosition, int size)
{
	_playerPos = playerPosition;
	playerSize = size;

}

void Player::update()
{
	//
}

void Player::draw()
{
	DrawPoly(_playerPos, 3, playerSize, -90, YELLOW);
}