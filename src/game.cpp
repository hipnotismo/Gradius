#include "game.h"

GameState state;

Player* player = new Player(50.0f, 360.0f, 50.0f, 50.0f, 3, 100, 800.0f, 700.0f, true);
Enemy* enemy[3]; 

void game::init()
{
	enemy[0] = new Enemy(1400.0f, 360.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
	enemy[1] = new Enemy(2000.0f, 100.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
	enemy[2] = new Enemy(3000.0f, 600.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
	InitWindow(1280, 720, "Gradius V0.1");
}
void game::draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	player->setPlayer();
	for (int i = 0; i < 3; i++)
	{
		enemy[i]->initEnemy();
	}
	EndDrawing();
}
void game::deInit()
{
	delete player;
	for (int i = 0; i < 3; i++)
	{
		delete enemy[i];
	}
	CloseWindow();
}
void game::update()
{
	player->input();
	for (int i = 0; i < 3; i++)
	{
		enemy[i]->movement();
		if (enemy[i]->getX() <= -100.0f)
			enemy[i]->setX(1300.0f);
		if (CheckCollisionRecs(player->_player, enemy[i]->_enemy))
			player->setState(false);
	}
	if (player->getState()==false)
		game::deInit();
}
void game::executeGame()
{
	init();
	while (!WindowShouldClose())
	{
		update();
		draw();
	}
	game::deInit();
}