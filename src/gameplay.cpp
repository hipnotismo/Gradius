#include "gameplay.h"

#include "game.h"

static int lives = 3;
static const int ammo = 100;
static const int enemies = 4;
//static const int enemies2 = 2;
static int currentAmmo = 0;
static const int startAmmo = 100;
static int winCount = 0;

Player* player = new Player(50.0f, 360.0f, 50.0f, 50.0f, lives, startAmmo,800.0f, 700.0f, true);
Enemy* enemy[4];
//Enemy2* enemy2[2];
Bullet* bullets[100];

static int newAmmo = player->getAmmo();

void initElements()
{
	for (int i = 0; i < enemies; i++)
	{
		enemy[i] = NULL;
	}
	for (int i = 0; i < ammo; i++)
	{
		bullets[i] = NULL;
	}
	enemy[0] = new Enemy(1400.0f, 360.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
	enemy[1] = new Enemy(2000.0f, 100.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
	enemy[2] = new Enemy(3000.0f, 600.0f, 20.0f, 20.0f, 300.0f, 300.0f, true);
	enemy[3] = new Enemy(2500.0f, 620.0f, 50.0f, 50.0f, 300.0f, 300.0f, true);
	
	//enemy2[0] = new Enemy2(1400.0f, static_cast<float>(GetScreenHeight()), 40.0f, 40.0f, 300.0f, 300.0f, true);

	for (int i = 0; i < ammo; i++)
	{
		bullets[i] = new Bullet(player->getX(),player->getY(), 1500.0f);
	}
}
void setCollisions()
{
	for (int i = 0; i < enemies; i++)
	{
		if (CheckCollisionRecs(player->_player, enemy[i]->_enemy))
		{
			player->setLives(lives--);
			player->setX(50.0f);
			player->setY(360.0f);
			delete enemy[i];
			winCount++;
		}
	}
	for (int i = 0; i < ammo; i++)
	{
		int j;
		j = i;
		if (i>2)
		{
			j = 2;
		}
		if (CheckCollisionCircleRec(bullets[i]->ball, radius, enemy[j]->_enemy))
		{
			delete enemy[j];
			delete bullets[i];
			winCount++;
		}
		/*if (CheckCollisionCircleRec(bullets[i]->ball, radius, enemy2[j]->_enemy))
		{
			delete enemy2[j];
			delete bullets[i];
			winCount++;
		}*/
	}
	for (int i = 0; i < ammo; i++)
	{
		if (bullets[i]->getX() > screenWidth)
		{
			if (bullets[i] != NULL)
				delete bullets[i];
		}

	}
}
void setRules()
{
	for (int i = 0; i < enemies; i++)
	{
		if (enemy[i]->getX() <= -100.0f)
			enemy[i]->setX(1300.0f);
	}
	/*for (int i = 0; i < enemies2; i++)
	{
		if (enemy2[i]->getX2() <= -100.0f)
			enemy2[i]->setX2(1300.0f);
	}*/
	if (player->getLives() <= 0)
	{
		player->setState(false);
	}
	if (player->getState() == false)
	{
		state = Credits;
	}
	for (int i = 0; i < enemies; i++)
	{
		if (winCount == 3 && player->getState()==true)
		{
			state = Credits;
		}
	}
}
void updateGameplay()
{
	player->input();
	for (int i = 0; i < enemies; i++)
	{
		enemy[i]->movement();
	}
	/*for (int i = 0; i < enemies; i++)
	{
		enemy2[i]->movement2();
	}*/
	if (IsKeyPressed(KEY_SPACE) && bullets[currentAmmo]  != NULL)
	{
		bullets[currentAmmo]->setY(player->getY()+25.0f);
		bullets[currentAmmo]->setX(player->getX());
		bullets[currentAmmo]->shoot();
		currentAmmo++;
		player->setAmmo(newAmmo--);
	}
 	for (int i = 0; i < ammo; i++)
	{
		if (bullets[i]->shooted == true)
		{
			bullets[i]->moveShoot();
		}
 	}
}
void drawGameplay()
{
	BeginDrawing();
	ClearBackground(BLACK);
	player->setPlayer();
	for (int i = 0; i < 4; i++)
	{
		enemy[i]->initEnemy();
	}
	/*for (int i = 0; i < 3; i++)
	{
		enemy2[i]->initEnemy2();
	}*/
	for (int i = 0; i < ammo; i++)
	{
		if (bullets[i]->shooted == true)
		{
			bullets[i]->createBullet();
		}
	}
	DrawText(TextFormat("Lives %i", player->getLives()), 50, 20, 40, GREEN);
	DrawText(TextFormat("Ammo %i", player->getAmmo()), 50, 60, 40, GREEN);
	EndDrawing();
}