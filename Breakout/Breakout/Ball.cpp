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
		static Ball ball = { 0 };

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