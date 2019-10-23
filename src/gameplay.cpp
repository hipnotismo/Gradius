#include "gameplay.h"

#include "game.h"

static int lives = 3;

Player* player = new Player(50.0f, 360.0f, 50.0f, 50.0f, lives, 100, 800.0f, 700.0f, true);
Enemy* enemy[3];

void initElements()
{
	enemy[0] = new Enemy(1400.0f, 360.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
	enemy[1] = new Enemy(2000.0f, 100.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
	enemy[2] = new Enemy(3000.0f, 600.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
}
void setCollisions()
{
	for (int i = 0; i < 3; i++)
	{
		if (CheckCollisionRecs(player->_player, enemy[i]->_enemy))
			player->setState(false);
	}
}
void setRules()
{
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i]->getX() <= -100.0f)
			enemy[i]->setX(1300.0f);
	}
	if (player->getState() == false)
	{
		player->setLives(lives--);
		player->setX(50.0f);
		player->setY(360.0f);
		player->setState(true);
	}
	if (player->getLives() <= 0)
		state = gameOver;
}
void updateGameplay()
{
	player->input();
	for (int i = 0; i < 3; i++)
	{
		enemy[i]->movement();
	}
}
void drawGameplay()
{
	BeginDrawing();
	ClearBackground(BLACK);
	player->setPlayer();
	for (int i = 0; i < 3; i++)
	{
		enemy[i]->initEnemy();
	}
	DrawText(TextFormat("Lives %i", player->getLives()), 50, 20, 40, GREEN);
	EndDrawing();
}