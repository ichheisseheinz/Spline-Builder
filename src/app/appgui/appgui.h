#pragma once

#include "raylib.h"
#include "../../raygui.h"

namespace appgui
{
	class AppGUI
	{
	public:
		AppGUI(int width, int height);

		void Background(int spacing);
		void UI();
	private:
		int width;
		int height;

		bool showMessageBox = false;
	};
}