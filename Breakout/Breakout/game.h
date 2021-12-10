#pragma once

namespace app
{
	namespace game
	{
		void InitValues();
		void UpdateFrame();
		void Draw();
		void ResetValues();

		extern bool victory;
		extern bool gameOver;
	}
}