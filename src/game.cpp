#include "game.h"
Player* player = new Player(50.0f, 360.0f, 50.0f, 50.0f, 3, 100, 800.0f, 700.0f, true);
Enemy* enemy = new Enemy(1250.0f, 360.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
void init()
{
	InitWindow(1280, 720, "Gradius V0.1");
}
void draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	player->setPlayer();
	enemy->initEnemy();
	EndDrawing();
}
void deInit()
{
	delete player;
	delete enemy;
	CloseWindow();
}
void update()
{
	player->input();
	enemy->movement();
	if (CheckCollisionRecs(player->_player, enemy->_enemy))
		player->setState(false);
	if (player->getState()==false)
		deInit();
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