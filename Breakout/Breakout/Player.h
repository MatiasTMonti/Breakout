#pragma once
#include "raylib.h"

namespace app
{
	namespace players
	{
		struct Player 
		{
			Vector2 position;
			Rectangle size;
			int life;
		};

		extern Player player;

		void InitPlayer();
		void UpdatePlayer();
		void DrawPlayer();
	}
}