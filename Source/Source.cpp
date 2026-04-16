#include <raylib.h>

#define SCREEN_X 1200
#define SCREEN_Y 700
#define WINDOW_TITLE "Sumo - VM Games"

int main()
{
	InitWindow(SCREEN_X, SCREEN_Y, WINDOW_TITLE);
	InitAudioDevice();

	float xPos = 0.f;
	float yPos = 0.f;
	float speed = 1500.f;
	int width = 30;
	int height = 30;

	// main game loop
	while (!WindowShouldClose())
	{
		BeginDrawing();

		if (IsKeyDown(KEY_RIGHT))
		{
			xPos += speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_LEFT))
		{
			xPos -= speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_UP))
		{
			yPos -= speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_DOWN))
		{
			yPos += speed * GetFrameTime();
		}

		DrawRectangle(xPos, yPos, width, height, WHITE);
		ClearBackground(BLACK);
		EndDrawing();
	}
	CloseAudioDevice();
	CloseWindow();

	return 0;
}