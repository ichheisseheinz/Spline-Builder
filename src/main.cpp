#include "raylib.h"

#include "bezier/bezier.h"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

int main()
{
	SetTraceLogLevel(LOG_WARNING | LOG_ERROR | LOG_FATAL);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Spline Builder by IchHeisseHeinz");

	bezier::Bezier curve = bezier::Bezier(
		node::Node(Vector2{ 200, 500 }),
		node::Node(Vector2{ 300, 200 }),
		node::Node(Vector2{ 500, 200 }),
		node::Node(Vector2{ 600, 500 })
		);

	while (!WindowShouldClose())
	{
		curve.Update();

		BeginDrawing();

		ClearBackground(BLACK);
		
		curve.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}