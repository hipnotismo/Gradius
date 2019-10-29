#include "game.h"
#include "menu.h"

GameState state;

void game::init()
{
	InitWindow(1280, 720, "Gradius V0.1");
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