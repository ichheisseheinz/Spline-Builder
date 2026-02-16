#include "raylib.h"

#include "bezier/bezier.h"
#include "appgui/appgui.h"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

int main()
{
	SetTraceLogLevel(LOG_WARNING | LOG_ERROR | LOG_FATAL);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Spline Builder by IchHeisseHeinz");

	bezier::Bezier curve = bezier::Bezier(
		node::Node(Vector2{ 350, 500 }),
		node::Node(Vector2{ 450, 200 }),
		node::Node(Vector2{ 650, 200 }),
		node::Node(Vector2{ 750, 500 })
		);

	while (!WindowShouldClose())
	{
		curve.Update();

		BeginDrawing();

		ClearBackground(BLACK);

		appgui::Background(SCREEN_WIDTH, SCREEN_HEIGHT, 50);
		curve.Draw();
		appgui::UI();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}