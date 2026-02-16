#include "node.h"
#include "raymath.h"

using namespace node;

Node::Node(Vector2 position) :
	position(position), active(false)
{ }

void Node::Update()
{
	Vector2 pos = GetMousePosition();
	Rectangle boundingRec = Rectangle{ position.x - 5, position.y - 5, 10, 10 };
	if (!active && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (CheckCollisionPointRec(pos, boundingRec))) active = true;
	else if (active && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) active = false;

	// Check if mouse intersects node bounds
	if (active && IsMouseButtonDown(MOUSE_BUTTON_LEFT) &&
		((CheckCollisionPointRec(pos, boundingRec)) ||
		CheckCollisionPointRec(pos - GetMouseDelta(), boundingRec)))
	{
		position += GetMouseDelta();
	}
}

void Node::Draw()
{
	DrawCircleLinesV(position, 5, WHITE);
}

Vector2 Node::GetPosition()
{
	return position;
}