#include "appgui.h"

using namespace appgui;

AppGUI::AppGUI(int width, int height) :
	width(width), height(height)
{ }

void AppGUI::Background(int spacing)
{
	for (int row = 0; row < height; row += spacing)
	{
		DrawLine(0, row, width, row, GRAY);
	}

	for (int col = 0; col < width; col += spacing)
	{
		DrawLine(col, 0, col, height, GRAY);
	}
}

void AppGUI::UI()
{
	if (GuiButton(Rectangle{ 24, 24, 120, 30 }, "#191#Info")) showMessageBox = true;

	if (showMessageBox)
	{
		int result = GuiMessageBox(Rectangle{ 85, 70, 250, 100 },
			"#191#Message Box", "This doesn't do anything yet\nJust trying out raygui", "Gimme some time;Lemme be");

		if (result >= 0) showMessageBox = false;
	}
}