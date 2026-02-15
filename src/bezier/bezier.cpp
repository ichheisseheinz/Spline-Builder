#include "bezier.h"
#include "raymath.h"
#include <cmath>

using namespace bezier;

Bezier::Bezier(node::Node p0, node::Node p1, node::Node p2, node::Node p3) :
	p0(p0), p1(p1), p2(p2), p3(p3)
{ }

void Bezier::Update()
{
	p0.Update();
	p1.Update();
	p2.Update();
	p3.Update();
}

void Bezier::Draw()
{
	DrawCircleLinesV(p0.GetPosition(), 5, WHITE);
	DrawCircleLinesV(p1.GetPosition(), 5, WHITE);
	DrawCircleLinesV(p2.GetPosition(), 5, WHITE);
	DrawCircleLinesV(p3.GetPosition(), 5, WHITE);

	DrawLineV(p0.GetPosition(), p1.GetPosition(), WHITE);
	DrawLineV(p2.GetPosition(), p3.GetPosition(), WHITE);

	/*
	[1 t t^2 t^3] [ 1  0  0 0] [p0]
	              [-3  3  0 0] [p1]
	              [ 3 -6  3 0] [p2]
	              [-1  3 -3 1] [p3]
	              [-1  3 -3 1] [p3]
	*/
	Vector2 last = p0.GetPosition();
	Vector2 current;
	for (float t = 0.02; t <= 1; t += 0.02)
	{
		current = p0.GetPosition() +
			((p0.GetPosition() * -3) + (p1.GetPosition() * 3)) * t +
			((p0.GetPosition() * 3) + (p1.GetPosition() * -6) + (p2.GetPosition() * 3)) * std::pow(t, 2) +
			((p0.GetPosition() * -1) + (p1.GetPosition() * 3) + (p2.GetPosition() * -3) + p3.GetPosition()) * std::pow(t, 3);
		DrawLineV(last, current, RAYWHITE);
		last = current;
	}
}
