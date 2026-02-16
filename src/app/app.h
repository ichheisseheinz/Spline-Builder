#pragma once

#include "raylib.h"
#include "appgui/appgui.h"
#include "../bezier/bezier.h"

namespace app
{
	class App
	{
	public:
		App(int width, int height);

		void Update();
		void Draw();
	private:
		int width;
		int height;

		bezier::Bezier curve;
		appgui::AppGUI gui;
	};
}