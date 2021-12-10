#pragma once

#include "raylib.h"

namespace app
{
	namespace powerup
	{
		struct PowerUp
		{
			Vector2 pos;
			Rectangle size;
			bool active;
			Color color;
		};

		extern PowerUp upgrade;
		extern bool activePowerupPlayer;

		void InitPowerUp();
		void UpdatePowerUp();
		void DrawPowerUp();
	}
}