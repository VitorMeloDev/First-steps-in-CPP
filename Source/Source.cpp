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

class Paddle
{
public:
	float x, y;
	float width, height;
	float speed;

	void Draw()
	{
		DrawRectangle(x, y, width, height, WHITE);
	}

	void Update()
	{
		if (IsKeyDown(KEY_UP) && y > 0)
		{
			y -= speed;
		}
		if (IsKeyDown(KEY_DOWN) && y + height < GetScreenHeight())
		{
			y += speed;
		}
	}
};

class CPUPaddle : public Paddle
{
public:
	void Update(int yBall)
	{
		if (y + height/2 > yBall && y > 0)
		{
			y -= speed;
		}
		if (y + height / 2 < yBall && y + height < GetScreenHeight())
		{
			y += speed;
		}
	}
};

Ball ball;
Paddle player;
CPUPaddle cpuPaddle;

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

	player.speed = 6.f;
	player.width = 25.f;
	player.height = 120.f;
	player.x = 10;
	player.y = (screenHeight / 2) - (player.height / 2);

	cpuPaddle.speed = 6.f;
	cpuPaddle.width = 25.f;
	cpuPaddle.height = 120.f;
	cpuPaddle.x = screenWidth - cpuPaddle.width - 10;
	cpuPaddle.y = (screenHeight / 2) - (cpuPaddle.height / 2);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		// Update
		ball.Update();
		player.Update();
		cpuPaddle.Update(ball.y);

		// Drawing
		ClearBackground(BLACK);
		DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
		ball.Draw();
		player.Draw();
		cpuPaddle.Draw();
		DrawFPS(10, 10);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}