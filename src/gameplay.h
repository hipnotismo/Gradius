#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "init_enemy.h"
#include "init_enemy2.h"
#include "init_player.h"
#include "init_bullet.h"
void initElements();
void setCollisions();
void setRules();
void updateGameplay();
void drawGameplay();
#endif // !GAMEPLAY_H
