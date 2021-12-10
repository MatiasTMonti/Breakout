#pragma once
#include "raylib.h"

namespace app
{
	namespace balls
	{
		struct Ball 
		{
			Vector2 position;
			Vector2 speed;
			int radius;
			bool active;
		};

		extern Ball ball;
		extern bool pauseSoundBall;

		void InitBall();
		void UpdateBall();
		void DrawBall();
		void UnloadBall();
	}
}