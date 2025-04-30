/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/


/*TODO:
	- make bullets
	- seperate bullets into player bullets and enemy bullets
	- make sure enemies can essentially spam bullets
	- add collision
	- add scoring
	- add death screens
	- add restart
	- save high scores to a file to read via ifstream and ofstream
	- maybe add a start screen
	- maybe add textures
	- edit this list as needed in the future
*/

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"
#include "raymath.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <vector>
#include <iostream>

int main ()
{
	const int screenWidth = 1280;
	const int screenHeight = 800;
	const int playerSize = 25;
	float enemySpawnTime = 0.0f;
	float dashLeftCooldown = 0.0f;
	float dashRightCooldown = 0.0f;
	float shootCooldown = 0.0f;
	float angle = 0.0f;
	bool hasDashedLeft = false;
	bool hasDashedRight = false;
	bool gunOverheat = false;
	int score = 0;
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Bullethell Galaga");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	Vector2 playerPosition = { ((float)screenWidth / 2)-170, (float)screenHeight - 75 };
	Vector2 enemyPosition;
	std::vector<Enemy*> enemies;
	std::vector<Bullet*> bullets;
	Player player(playerPosition, playerSize);
	SetTargetFPS(60);
	// game loop
	int enemySpeed;
	for (int i = 0; i < 5; i++) {
		enemyPosition = { (float)GetRandomValue(85, screenWidth - 335), 0 };
		enemies.push_back(new Enemy(enemyPosition, 2));
	}
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		//timer for enemy spawns
		enemySpawnTime += GetFrameTime();
		//cooldown timer
		if (hasDashedLeft) {
			dashLeftCooldown += GetFrameTime();
			if (dashLeftCooldown >= 1.5f) {
				hasDashedLeft = false;
				dashLeftCooldown = 0.0f;
			}
		}
		if (hasDashedRight) {
			dashRightCooldown += GetFrameTime();
			if (dashRightCooldown >= 1.5f) {
				hasDashedRight = false;
				dashRightCooldown = 0.0f;
			}
		}
		if (gunOverheat) {
			shootCooldown += GetFrameTime();
			if (shootCooldown >= 2.0f) {
				gunOverheat = false;
				shootCooldown = 0.0f;
			}
		}
		if (IsKeyDown(KEY_RIGHT)) {
			playerPosition.x += 9.5;
			if (playerPosition.x > (screenWidth - 280) - playerSize) {
				playerPosition.x = screenWidth - 280 - playerSize;
			}
			player.setPlayerX(playerPosition.x);
		}
		if (IsKeyDown(KEY_LEFT)) {
			playerPosition.x -= 9.5;
			if (playerPosition.x < 30 + playerSize) {
				playerPosition.x = playerSize + 30;
			}
			player.setPlayerX(playerPosition.x);
		}
		if (IsKeyPressed(KEY_Z) && !hasDashedLeft) {
			playerPosition.x -= 195;
			if (playerPosition.x < 30 + playerSize) {
				playerPosition.x = playerSize + 30;
			}
			player.setPlayerX(playerPosition.x);
			hasDashedLeft = true;
		}
		if (IsKeyPressed(KEY_C) && !hasDashedRight) {
			playerPosition.x += 195;
			if (playerPosition.x > (screenWidth - 280) - playerSize) {
				playerPosition.x = screenWidth - 280 - playerSize;
			}
			player.setPlayerX(playerPosition.x);
			hasDashedRight = true;
		}
		if (IsKeyPressed(KEY_X) && !gunOverheat) {
			bullets.push_back(new PlayerBullet(playerPosition, Bullet::Type::Player));
			std::cout << "shot" << std::endl;
			if (bullets.size() > 4) {
				gunOverheat = true;
			}
		}

		if (enemySpawnTime >= 7.5f) {
			for (int i = 0; i < GetRandomValue(1, 5); i++) {
				enemyPosition = { (float)GetRandomValue(85, screenWidth - 335), 0 };
				enemies.push_back(new Enemy(enemyPosition, 2));
				std::cout << i+1 << std::endl;
			}
			enemySpawnTime = 0.0f;
		}
		angle += .1f;
		for (Enemy* enemy : enemies) {
			int spawnBullet = GetRandomValue(0, 1000);
			if (enemy->getEnemyY() < 100) {
				
				
				enemy->setEnemyX(enemy->getEnemyX()+(5*cosf(angle)));
				if (enemy->getEnemyX() <= 55) {
					enemy->setEnemyX(55);
				}
				if (enemy->getEnemyX() >= screenWidth - 305) {
					enemy->setEnemyX(screenWidth-305);
				}
				enemy->setEnemyY(enemy->getEnemyY() + 2);
				
			}
			if (enemy->getEnemyY() >= 100) {
				enemy->setEnemyX(enemy->getEnemyX() + enemy->getSpeed());
			}
			if (enemy->getEnemyX() <= 55 || enemy->getEnemyX() >= screenWidth - 305) {
				enemy->reverse();
			}
			if (spawnBullet > 990) {
				bullets.push_back(new EnemyBullet(Vector2{ enemy->getEnemyX(), enemy->getEnemyY() }, Bullet::Type::Enemy));
			}
		}

		for (Bullet* bullet : bullets) {
			switch (bullet -> getType())
			{
			case Bullet::Type::Player:
				bullet->update();
				if (bullet->getBulletY() < 0) {
					bullets.erase(bullets.begin());
					std::cout << "deleted" << std::endl;
				}
				break;
			case Bullet::Type::Enemy:
				bullet->update();
				if (bullet->getBulletY() > screenHeight) {
					bullets.erase(bullets.begin());
					std::cout << "deleted" << std::endl;
				}

				break;
			default:
				break;
			}
			bullet->draw();
		}
		for (int i = 0; i < enemies.size(); i++) {
			for (int j = 0; j < bullets.size(); j++) {
				if (bullets[j]->getType() == Bullet::Type::Player) {
					if (CheckCollisionCircles(Vector2{ enemies[i]->getEnemyX(), enemies[i]->getEnemyY() }, 25, bullets[j]->getBulletPositionVector(), 5)) {
						delete enemies[i];
						enemies.erase(enemies.begin() + i);
						delete bullets[j];
						bullets.erase(bullets.begin() + j);
						i--;
						j--;
						break;
					}
				}
			}
		}

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);
		DrawRectangle(0, 0, 30, 800, GOLD);
		DrawRectangle(screenWidth-280, 0, 280, 800, GOLD);
		DrawRectangle(screenWidth - 240, 40, 200, 100, WHITE);
		// draw some text using the default font
		DrawText("Score:", screenWidth-240,20,20,BLACK);


		player.draw();
		for (auto enemy : enemies) {
			enemy -> draw();
		}
		
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
