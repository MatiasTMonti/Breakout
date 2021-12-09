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

		void InitBrick();
		void UpdateBrick();
		void DrawBrick();
		void UnloadBrick();
	}
}