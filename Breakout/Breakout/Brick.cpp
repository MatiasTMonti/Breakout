#include "Brick.h"

#include <cmath>
#include <cstdlib>

#include "ball.h"
#include "game.h"
#include "app.h"
#include "powerUp.h"

using namespace app;
using namespace game;
using namespace balls;
using namespace powerup;

namespace app
{
	namespace brick
	{
		int random;

		const int linesBricks = 5;
		const int brickPerLines = 20;

		static Brick brick[linesBricks][brickPerLines] = { 0 };
		static Vector2 brickSize = { 0 };

		void InitBrick()
		{
			brickSize = { static_cast<float>(GetScreenWidth()) / brickPerLines, 40 };

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

			InitPowerUp();
		}

		void UpdateBrick()
		{
			if (!gameOver)
			{
				random = rand() % 100 + 1;
				// Collision logic: ball vs bricks
				for (int i = 0; i < linesBricks; i++)
				{
					for (int j = 0; j < brickPerLines; j++)
					{
						if (brick[i][j].active)
						{

							// Hit below
							if (((ball.position.y - ball.radius) <= (brick[i][j].position.y + brickSize.y / 2)) &&
								((ball.position.y - ball.radius) > (brick[i][j].position.y + brickSize.y / 2 + ball.speed.y)) &&
								((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y < 0))
							{
								if (!activePowerupPlayer)
								{
									if (!upgrade.active)
									{
										if (random >= 10)
										{
											upgrade.pos = brick[i][j].position;
											upgrade.active = true;
										}
									}
								}

								brick[i][j].active = false;
								ball.speed.y *= -1;
							}
							// Hit above
							else if (((ball.position.y + ball.radius) >= (brick[i][j].position.y - brickSize.y / 2)) &&
								((ball.position.y + ball.radius) < (brick[i][j].position.y - brickSize.y / 2 + ball.speed.y)) &&
								((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y > 0))
							{
								brick[i][j].active = false;
								ball.speed.y *= -1;

								if (!upgrade.active)
								{
									if (random >= 80)
									{
										upgrade.pos = brick[i][j].position;
										upgrade.active = true;
									}
								}

							}
							// Hit left
							else if (((ball.position.x + ball.radius) >= (brick[i][j].position.x - brickSize.x / 2)) &&
								((ball.position.x + ball.radius) < (brick[i][j].position.x - brickSize.x / 2 + ball.speed.x)) &&
								((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x > 0))
							{
								brick[i][j].active = false;
								ball.speed.x *= -1;

								if (!upgrade.active)
								{
									if (random >= 80)
									{
										upgrade.pos = brick[i][j].position;
										upgrade.active = true;
									}
								}

							}
							// Hit right
							else if (((ball.position.x - ball.radius) <= (brick[i][j].position.x + brickSize.x / 2)) &&
								((ball.position.x - ball.radius) > (brick[i][j].position.x + brickSize.x / 2 + ball.speed.x)) &&
								((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x < 0))
							{
								brick[i][j].active = false;
								ball.speed.x *= -1;

								if (!upgrade.active)
								{
									if (random >= 80)
									{
										upgrade.pos = brick[i][j].position;
										upgrade.active = true;
									}
								}

							}
						}
					}
				}

				if (upgrade.active)
				{
					UpdatePowerUp();
					DrawPowerUp();
				}

				victory = true;

				for (int i = 0; i < linesBricks; i++)
				{
					for (int j = 0; j < brickPerLines; j++)
					{
						if (brick[i][j].active)
						{
							victory = false;
						}
					}
				}

				if (victory)
				{
					currentScreen = GameOver;
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
	}
}