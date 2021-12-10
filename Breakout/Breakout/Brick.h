#pragma once
#include "raylib.h"

namespace app
{
	namespace brick
	{
		struct Brick 
		{
			Vector2 position;
			bool active;
		};

		struct Ball
		{
			Vector2 position;
			Vector2 speed;
			int radius;
			bool active;
		};

		void InitBrick();
		void UpdateBrick();
		void DrawBrick();
	}
}