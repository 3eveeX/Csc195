/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/


/*TODO:
	+ make bullets
	+ seperate bullets into player bullets and enemy bullets
	+ make sure enemies can essentially spam bullets
	+ add collision
	+ add scoring
	- add death screens
	- add restart
	+ save high scores to a file to read via ifstream and ofstream
	- maybe add a start screen
	- maybe add textures
	- edit this list as needed in the future
*/

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"
#include "Scoreboard.h"
#include "raymath.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <vector>
#include <iostream>
#include <fstream>
#include <string>




int main ()
{
	const int screenWidth = 1280;
	const int screenHeight = 800;
	const int playerSize = 25;
	float enemySpawnTime;
	float dashLeftCooldown = 0.0f;
	float dashRightCooldown = 0.0f;
	float shootCooldown = 0.0f;
	float angle = 0.0f;
	bool hasDashedLeft = false;
	bool hasDashedRight = false;
	bool gunOverheat = false;
	int score = 0;
	std::string scoreString = "0";
	
	

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Bullethell Galaga");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	Vector2 playerPosition = { ((float)screenWidth / 2)-170, (float)screenHeight - 75 };
	Vector2 enemyPosition;
	std::vector<Enemy*> enemies;
	std::vector<Bullet*> playerBullets;
	std::vector<Bullet*> enemyBullets;
	Player player(playerPosition, playerSize);
	Scoreboard scoreboard;
	SetTargetFPS(60);
	// game loop
	int enemySpeed;
	bool start = true;
	bool play = false;
	bool dead = false;
	bool controls = false;
	
	std::cout << "Current Working Dir: " << GetWorkingDirectory() << std::endl;
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		if (start) {
			BeginDrawing();

			// Setup the back buffer for drawing (clear color and depth buffers)
			ClearBackground(BLACK);
			DrawRectangle(0, 0, 30, 800, GOLD);
			DrawRectangle(screenWidth - 280, 0, 280, 800, GOLD);
			DrawText("BulletHell", 30, 20, 202, RAYWHITE);
			DrawText("GALAGA", 60, 220, 202, GREEN);
			if (GetMouseX() > screenWidth - 240 && GetMouseX() < screenWidth - 40 && GetMouseY() > 20 && GetMouseY() < 100) {
				DrawRectangle(screenWidth - 240, 20, 200, 80, DARKGRAY);
				DrawText("Start", screenWidth - 220, 40, 30, GRAY);

				if (IsMouseButtonPressed(0)) {
					enemySpawnTime = 0.0f;
					score = 0;
					for (int i = 0; i < 5; i++) {
						enemyPosition = { (float)GetRandomValue(85, screenWidth - 335), 0 };
						enemies.push_back(new Enemy(enemyPosition, 2));
					}
					start = false;
					play = true;
				}

			}
			else {
				DrawRectangle(screenWidth - 240, 20, 200, 80, GRAY);
				DrawText("Start", screenWidth - 220, 40, 30, LIGHTGRAY);
			}
			scoreboard.update();
			scoreboard.draw();
			EndDrawing();
		}

		if (play) {
			scoreboard.update();
			//timer for enemy spawns
			enemySpawnTime += GetFrameTime();
			//==cooldown timers==
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
			//==inputs==
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
				playerBullets.push_back(new PlayerBullet(playerPosition, Bullet::Type::Player));
				std::cout << "shot" << std::endl;
				if (playerBullets.size() > 4) {
					gunOverheat = true;
				}

			}
			if (score <= 25) {
				if (enemySpawnTime >= 7.5f) {
					for (int i = 0; i < GetRandomValue(1, 5); i++) {
						enemyPosition = { (float)GetRandomValue(85, screenWidth - 335), 0 };
						enemies.push_back(new Enemy(enemyPosition, 2));
						std::cout << i + 1 << std::endl;
					}
					enemySpawnTime = 0.0f;
				}
			}
			else if (score > 25 && score <= 50) {
				if (enemySpawnTime >= 3.75f) {
					for (int i = 0; i < GetRandomValue(1, 5); i++) {
						enemyPosition = { (float)GetRandomValue(85, screenWidth - 335), 0 };
						enemies.push_back(new Enemy(enemyPosition, 2));
						std::cout << i + 1 << std::endl;
					}
					enemySpawnTime = 0.0f;
				}
			}
			else if (score > 50 && score <= 75) {
				if (enemySpawnTime >= 3.75f) {
					for (int i = 0; i < GetRandomValue(1, 5); i++) {
						enemyPosition = { (float)GetRandomValue(85, screenWidth - 335), 0 };
						enemies.push_back(new Enemy(enemyPosition, 4));
						std::cout << i + 1 << std::endl;
					}
					enemySpawnTime = 0.0f;
				}
			}
			else if (score > 75) {
				if (enemySpawnTime >= 3.75f) {
					for (int i = 0; i < GetRandomValue(4, 8); i++) {
						enemyPosition = { (float)GetRandomValue(85, screenWidth - 335), 0 };
						enemies.push_back(new Enemy(enemyPosition, 4));
						std::cout << i + 1 << std::endl;
					}
					enemySpawnTime = 0.0f;
				}
			}
			angle += .1f;
			for (Enemy* enemy : enemies) {
				int spawnBullet = GetRandomValue(0, 1000);
				if (enemy->getEnemyY() < 100) {


					enemy->setEnemyX(enemy->getEnemyX() + (5 * cosf(angle)));
					if (enemy->getEnemyX() <= 55) {
						enemy->setEnemyX(55);
					}
					if (enemy->getEnemyX() >= screenWidth - 305) {
						enemy->setEnemyX(screenWidth - 305);
					}
					enemy->setEnemyY(enemy->getEnemyY() + 2);

				}
				if (enemy->getEnemyY() >= 100) {
					enemy->setEnemyX(enemy->getEnemyX() + enemy->getSpeed());
				}
				if (enemy->getEnemyX() <= 55 || enemy->getEnemyX() >= screenWidth - 305) {
					enemy->reverse();
				}
				if (spawnBullet > 965) {
					enemyBullets.push_back(new EnemyBullet(Vector2{ enemy->getEnemyX(), enemy->getEnemyY() }, Bullet::Type::Enemy));
				}
			}

			for (Bullet* bullet : playerBullets) {
				bullet->update();
				if (bullet->getBulletY() < 0) {
					delete bullet;
					playerBullets.erase(playerBullets.begin());
					std::cout << "deleted" << std::endl;
					continue;
				}
				if (!playerBullets.empty()) {
					bullet->draw();
				}
			}
			for (Bullet* bullet : enemyBullets) {
				bullet->update();
				if (bullet->getBulletY() < 0) {
					delete bullet;
					enemyBullets.erase(enemyBullets.begin());
					continue;
				}
				if (!enemyBullets.empty()) {
					bullet->draw();
				}
			}
			for (int i = 0; i < enemies.size(); i++) {
				for (int j = 0; j < playerBullets.size(); j++) {

					if (CheckCollisionCircles(Vector2{ enemies[i]->getEnemyX(), enemies[i]->getEnemyY() }, 25, playerBullets[j]->getBulletPositionVector(), 5)) {
						delete enemies[i];
						enemies.erase(enemies.begin() + i);
						delete playerBullets[j];
						playerBullets.erase(playerBullets.begin() + j);
						i--;
						j--;
						scoreString = std::to_string(++score);
						break;
					}
				}
			}
			for (int i = 0; i < enemyBullets.size();) {
				if (CheckCollisionCircleRec(enemyBullets[i]->getBulletPositionVector(), 5, player.getPlayerBounds())) {
					delete enemyBullets[i];
					enemyBullets.erase(enemyBullets.begin() + i);
					std::cout << "You died. womp womp bitch" << std::endl;
					std::ofstream scoreWriteFApp("Scoreboard.txt", std::ios::app);
					scoreboard.streamOut(scoreWriteFApp, score);
					scoreWriteFApp.close();
					scoreboard.update();
					play = false;
					dead = true;
				}
				else {
					i++;
				}
			}
			// drawing
			BeginDrawing();

			// Setup the back buffer for drawing (clear color and depth buffers)
			ClearBackground(BLACK);
			DrawRectangle(0, 0, 30, 800, GOLD);
			DrawRectangle(screenWidth - 280, 0, 280, 800, GOLD);
			DrawRectangle(screenWidth - 240, 40, 200, 100, WHITE);
			// draw some text using the default font
			DrawText("Score:", screenWidth - 240, 20, 20, BLACK);
			DrawText(scoreString.c_str(), screenWidth - 220, 60, 50, BLACK);
			scoreboard.draw();
			player.update();
			player.draw();

			for (auto enemy : enemies) {
				enemy->draw();
			}
			for (auto bullet : playerBullets) {
				bullet->draw();
			}
			for (auto bullet : enemyBullets) {
				bullet->draw();
			}


			// end the frame and get ready for the next one  (display frame, poll input, etc...)
			EndDrawing();
		}
		if (dead) {
			BeginDrawing();

			// Setup the back buffer for drawing (clear color and depth buffers)
			ClearBackground(BLACK);
			DrawRectangle(0, 0, 30, 800, GOLD);
			DrawRectangle(screenWidth - 280, 0, 280, 800, GOLD);
			DrawText("Score: ", ((screenWidth - 280) / 2) - 100, (screenHeight / 2)-150, 75, WHITE);
			DrawText(scoreString.c_str(), ((screenWidth - 280) / 2) - 100, (screenHeight / 2), 50, WHITE);
			if (GetMouseX() > ((screenWidth - 280) / 2) - 100 && GetMouseX() < ((screenWidth - 280) / 2) + 100 && GetMouseY() > screenHeight - 150 && GetMouseY() < screenHeight - 70) {
				DrawRectangle(((screenWidth - 280) / 2) - 100, screenHeight - 150, 200, 80, DARKGRAY);
				DrawText("Replay", ((screenWidth - 280) / 2) - 80, screenHeight - 130, 30, GRAY);

				if (IsMouseButtonPressed(0)) {
					enemySpawnTime = 0.0f;
					score = 0;
					enemies.clear();
					enemyBullets.clear();
					playerBullets.clear();
					for (int i = 0; i < 5; i++) {
						enemyPosition = { (float)GetRandomValue(85, screenWidth - 335), 0 };
						enemies.push_back(new Enemy(enemyPosition, 2));
					}
					playerPosition = { ((float)screenWidth / 2) - 170, (float)screenHeight - 75 };
					player.update();
					dead = false;
					play = true;
				}

			}
			else {
				DrawRectangle(((screenWidth - 280) / 2) - 100, screenHeight - 150, 200, 80, GRAY);
				DrawText("Replay", ((screenWidth - 280) / 2) - 80, screenHeight - 130, 30, LIGHTGRAY);
			}
			if (GetMouseX() > ((screenWidth - 280) / 2) - 100 && GetMouseX() < ((screenWidth - 280) / 2) + 100 && GetMouseY() > screenHeight - 250 && GetMouseY() < screenHeight - 170) {
				DrawRectangle(((screenWidth - 280) / 2) - 100, screenHeight - 250, 200, 80, DARKGRAY);
				DrawText("Main Menu", ((screenWidth - 280) / 2) - 80, screenHeight - 230, 30, GRAY);

				if (IsMouseButtonPressed(0)) {
					
					enemies.clear();
					enemyBullets.clear();
					playerPosition = { ((float)screenWidth / 2) - 170, (float)screenHeight - 75 };
					player.update();
					dead = false;
					start = true;
				}

			}
			else {
				DrawRectangle(((screenWidth - 280) / 2) - 100, screenHeight - 250, 200, 80, GRAY);
				DrawText("Main Menu", ((screenWidth - 280) / 2) - 80, screenHeight - 230, 30, LIGHTGRAY);
			}
			EndDrawing();
		}
	}

	// cleanup
	// unload our texture so it can be cleaned up

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
