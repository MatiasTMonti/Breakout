#pragma once
#include "raylib.h"

namespace app
{
	namespace ball
	{
		struct Ball {
			Vector2 position;
			Vector2 speed;
			int radius;
			bool active;
		};

		extern Ball ball;

		void InitBall();
		void UpdateBall();
		void DrawBall();
		void UnloadBall();
	}
}