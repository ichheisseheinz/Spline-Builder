#include "raylib.h"

#include "bezier/bezier.h"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

int main()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Spline Builder by IchHeisseHeinz");

	bezier::Bezier curve = bezier::Bezier(
		Vector2{ 200, 500 },
		Vector2{ 300, 200 },
		Vector2{ 500, 200 },
		Vector2{ 600, 500 }
		);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		
		curve.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}