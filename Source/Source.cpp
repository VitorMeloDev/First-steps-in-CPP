#include <raylib.h>

#define SCREEN_X 1200
#define SCREEN_Y 700
#define WINDOW_TITLE "Sumo - VM Games"

struct Entity
{
	Rectangle rec;
	Color cor;
	float speed = 50.f;
};

void MovePlayer(Entity &player)
{
	if (IsKeyDown(KEY_RIGHT))
	{
		player.rec.x += player.speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_LEFT))
	{
		player.rec.x -= player.speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_UP))
	{
		player.rec.y -= player.speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_DOWN))
	{
		player.rec.y += player.speed * GetFrameTime();
	}
}

int main()
{
	InitWindow(SCREEN_X, SCREEN_Y, WINDOW_TITLE);
	InitAudioDevice();
	
	Entity player{ Rectangle{SCREEN_X / 2.f, SCREEN_Y / 2.f, 50.f, 50.f}, BLUE, 300.f };
	Entity enemy{ Rectangle{SCREEN_X / 3.f, SCREEN_Y / 3.f, 50.f, 50.f}, RED, 0.f };


	// main game loop
	while (!WindowShouldClose())
	{
		BeginDrawing();
		MovePlayer(player);
		DrawRectangle(player.rec.x , player.rec.y, player.rec.width, player.rec.height, player.cor);
		DrawRectangle(enemy.rec.x, enemy.rec.y, enemy.rec.width, enemy.rec.height, enemy.cor);

		if (CheckCollisionRecs(player.rec, enemy.rec))
		{
			player.cor = PURPLE;
		}
		else
		{
			player.cor = BLUE;
		}

		ClearBackground(BLACK);
		EndDrawing();
	}
	CloseAudioDevice();
	CloseWindow();

	return 0;
}