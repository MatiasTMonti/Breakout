#include "Ball.h"

#include "Player.h"
#include "game.h"

using namespace app;
using namespace game;
using namespace player;

namespace app 
{
	namespace ball
	{
		Ball ball = { 0 };

		void InitBall()
		{
			// Initialize ball
			ball.position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() * 7 / 8 - 30 };
			ball.speed = { 0, 0 };
			ball.radius = 7;
			ball.active = false;
		}

		void UpdateBall()
		{
			// Ball launching logic
			if (!ball.active)
			{
				if (IsKeyPressed(KEY_SPACE))
				{
					ball.active = true;
					ball.speed = { 0, -250 };
				}
			}

			// Ball movement logic
			if (ball.active)
			{
				ball.position.x += ball.speed.x * GetFrameTime();
				ball.position.y += ball.speed.y * GetFrameTime();
			}
			else
			{
				ball.position = { app::player::player.position.x, (float)GetScreenHeight() * 7 / 8 - 30 };
			}

			// Collision logic: ball vs walls
			if (((ball.position.x + ball.radius) >= GetScreenWidth()) || ((ball.position.x - ball.radius) <= 0)) ball.speed.x *= -1;
			if ((ball.position.y - ball.radius) <= 0) ball.speed.y *= -1;
			if ((ball.position.y + ball.radius) >= GetScreenHeight())
			{
				ball.speed = { 0, 0 };
				ball.active = false;

				app::player::player.life--;
			}

			// Collision logic: ball vs player
			if (CheckCollisionCircleRec(ball.position, ball.radius, { app::player::player.position.x - app::player::player.size.x / 2, app::player::player.position.y - app::player::player.size.y / 2, app::player::player.size.x, app::player::player.size.y }))
			{
				if (ball.speed.y > 0)
				{
					ball.speed.y *= -1;
					ball.speed.x = (ball.position.x - app::player::player.position.x) / (app::player::player.size.x / 2) * 5;
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

		}
	}
}