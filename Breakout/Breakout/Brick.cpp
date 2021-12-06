#include "Brick.h"

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