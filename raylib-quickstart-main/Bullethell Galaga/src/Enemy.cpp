#include "Enemy.h"

Enemy::Enemy(Vector2 enemyPosition, int speed)
{
	_enemyPos = enemyPosition;
	_speed = speed;
}

void Enemy::update()
{
//	
}

void Enemy::draw()
{
	DrawCircleV(_enemyPos, 25, RED);
}

void Enemy::setEnemyX(float x)
{
	_enemyPos.x = x;
}

void Enemy::setEnemyY(float y)
{
	_enemyPos.y = y;
}
