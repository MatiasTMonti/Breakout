#include "Brick.h"

#include "Ball.h"

#include <math.h>

using namespace app;
using namespace ball;

namespace app
{
	namespace brick
	{
		const int linesBricks = 5;
		const int brickPerLines = 20;

		static Brick brick[linesBricks][brickPerLines] = { 0 };
		static Vector2 brickSize = { 0 };

		void InitBrick()
		{
			brickSize = { (float)GetScreenWidth() / brickPerLines, 40 };

			// Initialize bricks
			int initialDownPosition = 50;

			for (int i = 0; i < linesBricks; i++)
			{
				for (int j = 0; j < brickPerLines; j++)
				{
					brick[i][j].position = { j * brickSize.x + brickSize.x / 2, i * brickSize.y + initialDownPosition };
					brick[i][j].active = true;
				}
			}
		}

		void UpdateBrick()
		{
			// Collision logic: ball vs bricks
			for (int i = 0; i < linesBricks; i++)
			{
				for (int j = 0; j < brickPerLines; j++)
				{
					if (brick[i][j].active)
					{
						// Hit below
						if (((app::ball::ball.position.y - app::ball::ball.radius) <= (brick[i][j].position.y + brickSize.y / 2)) &&
							((app::ball::ball.position.y - app::ball::ball.radius) > (brick[i][j].position.y + brickSize.y / 2 + app::ball::ball.speed.y)) &&
							((fabs(app::ball::ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + app::ball::ball.radius * 2 / 3)) && (app::ball::ball.speed.y < 0))
						{
							brick[i][j].active = false;
							app::ball::ball.speed.y = app::ball::ball.speed.y -200 * GetFrameTime();
						}
						// Hit above
						else if (((app::ball::ball.position.y + app::ball::ball.radius) >= (brick[i][j].position.y - brickSize.y / 2)) &&
							((app::ball::ball.position.y + app::ball::ball.radius) < (brick[i][j].position.y - brickSize.y / 2 + app::ball::ball.speed.y)) &&
							((fabs(app::ball::ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + app::ball::ball.radius * 2 / 3)) && (app::ball::ball.speed.y > 0))
						{
							brick[i][j].active = false;
							app::ball::ball.speed.y = app::ball::ball.speed.y -200 * GetFrameTime();
						}
						// Hit left
						else if (((app::ball::ball.position.x + app::ball::ball.radius) >= (brick[i][j].position.x - brickSize.x / 2)) &&
							((app::ball::ball.position.x + app::ball::ball.radius) < (brick[i][j].position.x - brickSize.x / 2 + app::ball::ball.speed.x)) &&
							((fabs(app::ball::ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + app::ball::ball.radius * 2 / 3)) && (app::ball::ball.speed.x > 0))
						{
							brick[i][j].active = false;
							app::ball::ball.speed.x = app::ball::ball.speed.y -200 * GetFrameTime();
						}
						// Hit right
						else if (((app::ball::ball.position.x - app::ball::ball.radius) <= (brick[i][j].position.x + brickSize.x / 2)) &&
							((app::ball::ball.position.x - app::ball::ball.radius) > (brick[i][j].position.x + brickSize.x / 2 + app::ball::ball.speed.x)) &&
							((fabs(app::ball::ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + app::ball::ball.radius * 2 / 3)) && (app::ball::ball.speed.x < 0))
						{
							brick[i][j].active = false;
							app::ball::ball.speed.x = app::ball::ball.speed.y -200 * GetFrameTime();
						}
					}
				}
			}

		}

		void DrawBrick()
		{
			for (int i = 0; i < linesBricks; i++)
			{
				for (int j = 0; j < brickPerLines; j++)
				{
					if (brick[i][j].active)
					{
						if ((i + j) % 2 == 0) DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, BLUE);
						else DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, SKYBLUE);
					}
				}
			}
		}

		void UnloadBrick()
		{

		}
	}
}