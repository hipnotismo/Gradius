#include "game.h"
#include "menu.h"
#include "credits.h"

GameState state;
const int screenWidth = 1280;
const int screenHeight = 720;

void game::init()
{
	InitWindow(screenWidth, screenHeight, "Gradius V0.1");
}
void game::draw()
{
	
}
void game::deInit()
{
	CloseWindow();
}
void game::update()
{
	
	switch (state)
	{
	case mainMenu:
		menu::updateMenu();
		menu::drawMenu();
		break;
	case controls:
		break;
	case gameplay:
		setCollisions();
		setRules();
		updateGameplay();
		drawGameplay();
		break;
	case gameOver:
		break;
	case Credits:
		cred::updateCredits();
		cred::drawCredits();
		break;
	}
}
void game::executeGame()
{
	init();
	initElements();
	while (!WindowShouldClose())
	{
		update();
		draw();
	}
	game::deInit();
}