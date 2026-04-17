#include <raylib.h>
#include <iostream>

using namespace std;

class Ball
{
public:
	float x, y;
	float speed_x, speed_y;
	float radius;

	void Draw()
	{
		DrawCircle(x, y, radius, WHITE);
	}

	void Update()
	{
		x += speed_x;
		y += speed_y;

		if (y + radius >= GetScreenHeight() || y - radius <= 0)
		{
			speed_y *= -1;
		}
		if (x + radius >= GetScreenWidth() || x - radius <= 0)
		{
			speed_x *= -1;
		}
	}
};

Ball ball;

int main()
{
	cout << "Starting the game" << endl;
	const int screenWidth = 1280;
	const int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "Pong - VM Games");
	SetTargetFPS(60);

	ball.radius = 20.f;
	ball.x = screenWidth / 2.f;
	ball.y = screenHeight / 2.f;
	ball.speed_x = 7;
	ball.speed_y = 7;

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		// Update
		ball.Update();

		// Drawing
		DrawFPS(10, 10);
		DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
		ball.Draw();
		DrawRectangle(10, screenHeight/2 - 60, 25, 120, WHITE);
		DrawRectangle(screenWidth - 35, screenHeight / 2 - 60, 25, 120, WHITE);
		ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}