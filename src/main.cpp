#include "raylib.h"

#include "app/app.h"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

int main()
{
	SetTraceLogLevel(LOG_WARNING | LOG_ERROR | LOG_FATAL);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Spline Builder by IchHeisseHeinz");

	app::App app = app::App(SCREEN_WIDTH, SCREEN_HEIGHT);

	while (!WindowShouldClose())
	{
		app.Update();

		BeginDrawing();

		ClearBackground(BLACK);

		app.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}