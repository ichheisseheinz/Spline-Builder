#pragma once

#include "raylib.h"

namespace node
{
	class Node
	{
	public:
		Node(Vector2 position);
		void Update();
		void Draw();
		Vector2 GetPosition();
	private:
		Vector2 position;
		bool active;
	};
}
