#include "Player.h"
#include "App.h"

using namespace app;

namespace app
{
	namespace player
	{
		Player player = { 0 };
		int lifes = 3;

		void InitPlayer()
		{
			// Initialize player
			player.position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() * 7 / 8 };
			player.size = { (float)GetScreenWidth() / 10, 20 };
			player.life = lifes;
		}

		void UpdatePlayer()
		{
			// Player movement logic
			if (IsKeyDown(KEY_LEFT)) player.position.x -= 350 * GetFrameTime();
			if ((player.position.x - player.size.x / 2) <= 0) player.position.x = player.size.x / 2;
			if (IsKeyDown(KEY_RIGHT)) player.position.x += 350 * GetFrameTime();
			if ((player.position.x + player.size.x / 2) >= GetScreenWidth()) player.position.x = GetScreenWidth() - player.size.x / 2;
		}

		void DrawPlayer()
		{
			// Draw player bar
			DrawRectangle(player.position.x - player.size.x / 2, player.position.y - player.size.y / 2, player.size.x, player.size.y, WHITE);

			// Draw player lives
			for (int i = 0; i < player.life; i++)
			{
				DrawRectangle(20 + 40 * i, GetScreenHeight() - 30, 35, 10, LIGHTGRAY);
			}
		}

		void UnloadPlayer()
		{

		}
	}
}