#pragma once

#include "raylib.h"
#include "../node/node.h"

namespace bezier
{
	class Bezier
	{
	public:
		Bezier(node::Node p0, node::Node p1, node::Node p2, node::Node p3);
		void Update();
		void Draw();
	private:
		node::Node p0;
		node::Node p1;
		node::Node p2;
		node::Node p3;
	};
}
