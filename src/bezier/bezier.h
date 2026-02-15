#pragma once

#include "raylib.h"

namespace bezier
{
	class Bezier
	{
	public:
		Bezier(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3);
		void Draw();
	private:
		Vector2 p0;
		Vector2 p1;
		Vector2 p2;
		Vector2 p3;
	};
}
