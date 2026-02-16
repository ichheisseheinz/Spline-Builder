#pragma once

#include "raylib.h"
#include "raygui.h"

namespace appgui
{
	static bool showMessageBox = false;

	void Background(int width, int height, int spacing);
	void UI();
}