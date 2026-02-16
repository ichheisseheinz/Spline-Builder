#include "app.h"

using namespace app;

App::App(int width, int height) :
	width(width), height(height),
	curve(bezier::Bezier(
		node::Node(Vector2{ 350, 500 }),
		node::Node(Vector2{ 450, 200 }),
		node::Node(Vector2{ 650, 200 }),
		node::Node(Vector2{ 750, 500 }))),
	gui(appgui::AppGUI(width, height))
{ }

void App::Update()
{
	curve.Update();
}

void App::Draw()
{
	gui.Background(50);
	curve.Draw();
	gui.UI();
}