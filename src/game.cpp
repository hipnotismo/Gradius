#include "game.h"

Player* player = new Player(50, 360, 50, 50, 3, 100, 800.0f, 700.0f, true);
void init()
{
	InitWindow(1280, 720, "Gradius V0.1");
}
void update()
{
	player->input();
}
void draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	player->setPlayer();
	EndDrawing();
}
void deInit()
{
	delete player;
	CloseWindow();
}
void game::executeGame()
{
	init();
	while (!WindowShouldClose())
	{
		update();
		draw();
	}
	deInit();
}