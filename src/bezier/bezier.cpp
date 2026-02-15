#include "bezier.h"
#include "raymath.h"
#include <cmath>

using namespace bezier;

Bezier::Bezier(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3) :
	p0(p0), p1(p1), p2(p2), p3(p3)
{ }

void Bezier::Draw()
{
	DrawCircleLinesV(p0, 5, WHITE);
	DrawCircleLinesV(p1, 5, WHITE);
	DrawCircleLinesV(p2, 5, WHITE);
	DrawCircleLinesV(p3, 5, WHITE);

	DrawLineV(p0, p1, WHITE);
	DrawLineV(p1, p2, WHITE);
	DrawLineV(p2, p3, WHITE);

	Vector2 last = p0;
	Vector2 current;
	for (float t = 0.01; t <= 1; t += 0.01)
	{
		current = p0 +
			((p0 * -3) + (p1 * 3)) * t +
			((p0 * 3) + (p1 * -6) + (p2 * 3)) * std::pow(t, 2) +
			((p0 * -1) + (p1 * 3) + (p2 * -3) + p3) * std::pow(t, 3);
		DrawLineV(last, current, RAYWHITE);
		last = current;
	}
}
