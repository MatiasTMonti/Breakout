#include "powerUp.h"

#include "player.h"
#include <iostream>

using namespace app;
using namespace players;

namespace app
{
	namespace powerup
	{
		PowerUp upgrade;
		bool activePowerupPlayer = false;
		int timer;

		void InitPowerUp()
		{
			upgrade.pos = { 0 };
			upgrade.size.width = 20;
			upgrade.size.height = 20;
			upgrade.color = ORANGE;
			upgrade.active = false;
			timer = 0;
		}

		void UpdatePowerUp()
		{
			timer += GetFrameTime();

			upgrade.pos.y++;

			if (upgrade.pos.y >= GetScreenHeight())
			{
				upgrade.active = false;
			}
		
			if (!activePowerupPlayer)
			{
				if (player.position.x - player.size.width / 2 < upgrade.pos.x + upgrade.size.width &&
					player.position.x - player.size.width / 2 + player.size.width > upgrade.pos.x &&
					player.position.y - player.size.height / 2 < upgrade.pos.y + upgrade.size.height &&
					player.position.y - player.size.height / 2 + player.size.height > upgrade.size.y)
				{
					activePowerupPlayer = true;
					upgrade.active = false;
					player.size.width = 150;
					player.size.height = 20;
				}
			}

			if (activePowerupPlayer)
			{
				if (timer >= 5)
				{
					player.size.width = static_cast<float>(GetScreenWidth()) / 10;
					player.size.height = 20;
					activePowerupPlayer = false;
				}
			}
		}

		void DrawPowerUp()
		{
			DrawRectangle(upgrade.pos.x, upgrade.pos.y, upgrade.size.width, upgrade.size.height, upgrade.color);
		}
	}
}