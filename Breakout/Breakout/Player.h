#pragma once
#include "raylib.h"

namespace app
{
	namespace players
	{
		struct Player 
		{
			Vector2 position;
			Vector2 size;
			int life;
		};

		extern Player player;

		void InitPlayer();
		void UpdatePlayer();
		void DrawPlayer();
	}
}