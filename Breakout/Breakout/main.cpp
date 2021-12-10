#include "app.h"

int main()
{
	app::ExecuteGame();
}


//#include "raylib.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
//
//const int PLAYER_MAX_LIFE = 5;
//const int LINES_OF_BRICKS = 5;
//const int BRICKS_PER_LINE = 20;
//
//enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;
//
//struct Player {
//	Vector2 position;
//	Vector2 size;
//	int life;
//};
//
//struct Ball {
//	Vector2 position;
//	Vector2 speed;
//	int radius;
//	bool active;
//};
//
//struct Brick {
//	Vector2 position;
//	bool active;
//};
//
////Pantalla
//static const int screenWidth = 800;
//static const int screenHeight = 450;
//
////Bools
//static bool gameOver = false;
//static bool pause = false;
//
////Entidades
//static Player player = { 0 };
//static Ball ball = { 0 };
//static Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE] = { 0 };
//static Vector2 brickSize = { 0 };
//
////Creacion
//static void InitGame();
//static void UpdateGame();
//static void DrawGame();
//static void UpdateDrawFrame();
//
////Main
//int main()
//{
//	InitWindow(screenWidth, screenHeight, "sample game: arkanoid");
//	InitGame();
//
//	SetTargetFPS(60);
//	// Main game loop
//	while (!WindowShouldClose())
//	{
//		UpdateDrawFrame();
//	}
//
//	CloseWindow();
//	return 0;
//}
//
////Init variables
//void InitGame(void)
//{
//	brickSize = { (float)GetScreenWidth() / BRICKS_PER_LINE, 40 };
//
//	// Initialize player
//	player.position = { screenWidth / 2, screenHeight * 7 / 8 };
//	player.size = { screenWidth / 10, 20 };
//	player.life = PLAYER_MAX_LIFE;
//
//	// Initialize ball
//	ball.position = { screenWidth / 2, screenHeight * 7 / 8 - 30 };
//	ball.speed = { 0, 0 };
//	ball.radius = 7;
//	ball.active = false;
//
//	// Initialize bricks
//	int initialDownPosition = 50;
//	for (int i = 0; i < LINES_OF_BRICKS; i++)
//	{
//		for (int j = 0; j < BRICKS_PER_LINE; j++)
//		{
//			brick[i][j].position = { j * brickSize.x + brickSize.x / 2, i * brickSize.y + initialDownPosition };
//			brick[i][j].active = true;
//		}
//	}
//}
//
//// Update game
//void UpdateGame()
//{
//	if (!gameOver)
//	{
//		if (IsKeyPressed('P')) pause = !pause;
//		if (!pause)
//		{
//			// Player movement logic
//			if (IsKeyDown(KEY_LEFT)) player.position.x -= 5;
//			if ((player.position.x - player.size.x / 2) <= 0) player.position.x = player.size.x / 2;
//			if (IsKeyDown(KEY_RIGHT)) player.position.x += 5;
//			if ((player.position.x + player.size.x / 2) >= screenWidth) player.position.x = screenWidth - player.size.x / 2;
//
//			// Ball launching logic
//			if (!ball.active)
//			{
//				if (IsKeyPressed(KEY_SPACE))
//				{
//					ball.active = true;
//					ball.speed = { 0, -5 };
//				}
//			}
//
//			// Ball movement logic
//			if (ball.active)
//			{
//				ball.position.x += ball.speed.x;
//				ball.position.y += ball.speed.y;
//			}
//			else
//			{
//				ball.position = { player.position.x, screenHeight * 7 / 8 - 30 };
//			}
//
//			// Collision logic: ball vs walls 
//			if (((ball.position.x + ball.radius) >= screenWidth) || ((ball.position.x - ball.radius) <= 0)) ball.speed.x *= -1;
//			if ((ball.position.y - ball.radius) <= 0) ball.speed.y *= -1;
//			if ((ball.position.y + ball.radius) >= screenHeight)
//			{
//				ball.speed = { 0, 0 };
//				ball.active = false;
//				player.life--;
//			}
//
//			// Collision logic: ball vs player
//			if (CheckCollisionCircleRec(ball.position, ball.radius, { player.position.x - player.size.x / 2, player.position.y - player.size.y / 2, player.size.x, player.size.y }))
//			{
//				if (ball.speed.y > 0)
//				{
//					ball.speed.y *= -1;
//					ball.speed.x = (ball.position.x - player.position.x) / (player.size.x / 2) * 5;
//				}
//			}
//
//			// Collision logic: ball vs bricks
//			for (int i = 0; i < LINES_OF_BRICKS; i++)
//			{
//				for (int j = 0; j < BRICKS_PER_LINE; j++)
//				{
//					if (brick[i][j].active)
//					{
//						// Hit below
//						if (((ball.position.y - ball.radius) <= (brick[i][j].position.y + brickSize.y / 2)) &&
//							((ball.position.y - ball.radius) > (brick[i][j].position.y + brickSize.y / 2 + ball.speed.y)) &&
//							((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y < 0))
//						{
//							brick[i][j].active = false;
//							ball.speed.y *= -1;
//						}
//						// Hit above
//						else if (((ball.position.y + ball.radius) >= (brick[i][j].position.y - brickSize.y / 2)) &&
//							((ball.position.y + ball.radius) < (brick[i][j].position.y - brickSize.y / 2 + ball.speed.y)) &&
//							((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y > 0))
//						{
//							brick[i][j].active = false;
//							ball.speed.y *= -1;
//						}
//						// Hit left
//						else if (((ball.position.x + ball.radius) >= (brick[i][j].position.x - brickSize.x / 2)) &&
//							((ball.position.x + ball.radius) < (brick[i][j].position.x - brickSize.x / 2 + ball.speed.x)) &&
//							((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x > 0))
//						{
//							brick[i][j].active = false;
//							ball.speed.x *= -1;
//						}
//						// Hit right
//						else if (((ball.position.x - ball.radius) <= (brick[i][j].position.x + brickSize.x / 2)) &&
//							((ball.position.x - ball.radius) > (brick[i][j].position.x + brickSize.x / 2 + ball.speed.x)) &&
//							((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x < 0))
//						{
//							brick[i][j].active = false;
//							ball.speed.x *= -1;
//						}
//					}
//				}
//			}
//
//			// Game over logic
//			if (player.life <= 0) gameOver = true;
//			else
//			{
//				gameOver = true;
//
//				for (int i = 0; i < LINES_OF_BRICKS; i++)
//				{
//					for (int j = 0; j < BRICKS_PER_LINE; j++)
//					{
//						if (brick[i][j].active) gameOver = false;
//					}
//				}
//			}
//		}
//	}
//	else
//	{
//		if (IsKeyPressed(KEY_ENTER))
//		{
//			InitGame();
//			gameOver = false;
//		}
//	}
//}
//// Draw game
//void DrawGame()
//{
//	BeginDrawing();
//	ClearBackground(RAYWHITE);
//	if (!gameOver)
//	{
//		// Draw player bar
//		DrawRectangle(player.position.x - player.size.x / 2, player.position.y - player.size.y / 2, player.size.x, player.size.y, BLACK);
//		// Draw player lives
//		for (int i = 0; i < player.life; i++) DrawRectangle(20 + 40 * i, screenHeight - 30, 35, 10, LIGHTGRAY);
//
//		// Draw ball
//		DrawCircleV(ball.position, ball.radius, MAROON);
//
//		// Draw bricks
//		for (int i = 0; i < LINES_OF_BRICKS; i++)
//		{
//			for (int j = 0; j < BRICKS_PER_LINE; j++)
//			{
//				if (brick[i][j].active)
//				{
//					if ((i + j) % 2 == 0) DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, GRAY);
//					else DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, DARKGRAY);
//				}
//			}
//		}
//
//		if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
//	}
//	else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);
//	EndDrawing();
//}
//
//// Update and Draw ()
//void UpdateDrawFrame()
//{
//	UpdateGame();
//	DrawGame();
//}