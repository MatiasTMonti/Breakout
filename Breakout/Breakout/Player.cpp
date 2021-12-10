#include "player.h"

#include "app.h"
#include "game.h"

using namespace app;
using namespace game;

namespace app
{
	namespace players
	{
		Player player = { 0 };

		void InitPlayer()
		{
			// Initialize player
			player.position = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) * 7 / 8 };
			player.size.width = static_cast<float>(GetScreenWidth()) / 10;
			player.size.height = 20;
			player.life = 3;
		}

		void UpdatePlayer()
		{
			if (!gameOver)
			{
				// Player movement logic
				if (IsKeyDown(KEY_LEFT)) player.position.x -= 350 * GetFrameTime();
				if ((player.position.x - player.size.width / 2) <= 0) player.position.x = player.size.width / 2;
				if (IsKeyDown(KEY_RIGHT)) player.position.x += 350 * GetFrameTime();
				if ((player.position.x + player.size.width / 2) >= GetScreenWidth()) player.position.x = GetScreenWidth() - player.size.width / 2;
			}
		}

		void DrawPlayer()
		{
			// Draw player bar
			DrawRectangle(player.position.x - player.size.width / 2, player.position.y - player.size.height / 2, player.size.width, player.size.height, WHITE);

			// Draw player lives
			for (int i = 0; i < player.life; i++)
			{
				DrawRectangle(20 + 40 * i, GetScreenHeight() - 30, 35, 10, LIGHTGRAY);
			}
		}
	}
}