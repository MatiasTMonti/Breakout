#include "ball.h"

#include "player.h"
#include "game.h"
#include "app.h"

using namespace app;
using namespace game;
using namespace players;

namespace app
{
	namespace balls
	{
		Ball ball = { 0 };

		bool pauseSoundBall = false;

		static Sound ballSound;

		void InitBall()
		{
			ballSound = LoadSound("res/impactsfx.ogg");

			// Initialize ball
			ball.position = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) * 7 / 8 - 30 };
			ball.speed = { 0, 0 };
			ball.radius = 7;
			ball.active = false;
		}

		void UpdateBall()
		{
			if (!gameOver)
			{
				// Ball launching logic
				if (!ball.active)
				{
					if (IsKeyPressed(KEY_SPACE))
					{
						ball.active = true;
						ball.speed = { 0, -5 };
					}
				}

				// Ball movement logic
				if (ball.active)
				{
					ball.position.x += ball.speed.x;
					ball.position.y += ball.speed.y;
				}
				else
				{
					ball.position = { player.position.x, static_cast<float>(GetScreenHeight()) * 7 / 8 - 30 };
				}

				// Collision logic: ball vs walls
				if (((ball.position.x + ball.radius) >= GetScreenWidth()) || ((ball.position.x - ball.radius) <= 0)) ball.speed.x *= -1;
				if ((ball.position.y - ball.radius) <= 0) ball.speed.y *= -1;
				if ((ball.position.y + ball.radius) >= GetScreenHeight())
				{
					ball.speed = { 0, 0 };
					ball.active = false;

					player.life--;
				}

				// Collision logic: ball vs player
				if (CheckCollisionCircleRec(ball.position, ball.radius, { player.position.x - player.size.width / 2, player.position.y - player.size.height / 2, player.size.width, player.size.height }))
				{
					if (ball.speed.y > 0)
					{
						ball.speed.y *= -1;
						ball.speed.x = (ball.position.x - player.position.x) / (player.size.width / 2) * 5;
					}

					if (!pauseSoundBall)
					{
						PlaySound(ballSound);
					}
					else
					{
						PauseSound(ballSound);
					}
				}

				// Game over logic
				if (player.life <= 0)
				{
					gameOver = true;
					currentScreen = GameOver;
				}
			}
		}

		void DrawBall()
		{
			// Draw ball
			DrawCircleV(ball.position, ball.radius, MAROON);
		}
		void UnloadBall()
		{
			UnloadSound(ballSound);
		}
	}
}