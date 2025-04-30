/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
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
	float angle = 0.0f;
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Bullethell Galaga");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	Vector2 playerPosition = { ((float)screenWidth / 2)-170, (float)screenHeight - 75 };
	Vector2 enemyPosition;
	std::vector<Enemy*> enemies;
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
		if (IsKeyPressed(KEY_Z)) {
			playerPosition.x -= 195;
			if (playerPosition.x < 30 + playerSize) {
				playerPosition.x = playerSize + 30;
			}
			player.setPlayerX(playerPosition.x);
		}
		if (IsKeyPressed(KEY_C)) {
			playerPosition.x += 195;
			if (playerPosition.x > (screenWidth - 280) - playerSize) {
				playerPosition.x = screenWidth - 280 - playerSize;
			}
			player.setPlayerX(playerPosition.x);
		}

		if (enemySpawnTime >= 60.0f) {
			for (int i = 0; i < GetRandomValue(1, 5); i++) {
				enemyPosition = { (float)GetRandomValue(85, screenWidth - 335), 0 };
				enemies.push_back(new Enemy(enemyPosition, 2));
				std::cout << i+1 << std::endl;
			}
			enemySpawnTime = 0.0f;
		}
		angle += .1f;
		for (Enemy* enemy : enemies) {
			if (enemy->getEnemyY() < 100) {
				
				
				enemy->setEnemyX(enemy->getEnemyX()+(5*cosf(angle)));
				enemy->setEnemyY(enemy->getEnemyY() + 2);
				
			}
			if (enemy->getEnemyY() >= 100) {
				enemy->setEnemyX(enemy->getEnemyX() + enemy->getSpeed());
			}
			if (enemy->getEnemyX() <= 55 || enemy->getEnemyX() >= screenWidth - 305) {
				enemy->reverse();
			}

		}
		

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);
		DrawRectangle(0, 0, 30, 800, GOLD);
		DrawRectangle(screenWidth-280, 0, 280, 800, GOLD);
		// draw some text using the default font
		DrawText("Hello Raylib", 200,200,20,WHITE);

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
