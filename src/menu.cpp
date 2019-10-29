#include "menu.h"
#include "game.h"

static Rectangle menu1;
static Rectangle menu2;
Rectangle menuSel;
Vector2 menuChoice;
static float radiusMenu = 5.0f;
static float menu2Pos = 425.0f;
static float menu1Pos = 325.0f;
static Color menuColor;
static Color creditsColor;

static void initRectangles()
{
	menu1.x = 580.0f;
	menu1.y = 300.0f;
	menu1.width = 150.0f;
	menu1.height = 50.0f;

	menu2.x = 550.0f;
	menu2.y = 400.0f;
	menu2.width = 200.0f;
	menu2.height = 50.0f;

	menuSel.x = 640.0f;
	menuSel.width = 10.0f;
	menuSel.height = 10.0f;

	menuChoice.x = 500.0f;
	menuChoice.y = 325.0f;
}

void menu::updateMenu()
{
	menuColor = MAROON;
	creditsColor = MAROON;
	initRectangles();
	if (IsKeyPressed(KEY_DOWN))
	{
		menuSel.y = menu2Pos;
	}
	if (IsKeyPressed(KEY_UP))
	{
		menuSel.y = menu1Pos;
	}
	if (CheckCollisionRecs(menu1, menuSel))
	{
		menuColor = BLUE;
	}
	if (CheckCollisionRecs(menu2, menuSel))
	{
		creditsColor = BLUE;
	}
	menuChoice.y = menuSel.y;
	if (IsKeyDown(KEY_ENTER) && CheckCollisionRecs(menu1, menuSel))
		state = gameplay;
	if (IsKeyDown(KEY_ENTER) && CheckCollisionRecs(menu2, menuSel))
		state = Credits;
}
void menu::drawMenu()
{
	BeginDrawing();
	ClearBackground(BLACK);
#ifdef COLLISION_BOX
	DrawRectangleRec(menu1, LIGHTGRAY);
	DrawRectangleRec(menu2, LIGHTGRAY);
	DrawRectangleRec(menuSel, BLUE);
#endif // COLLISION_BOX
	if (menuChoice.y == 325.0f || menuChoice.y==425.0f)
	DrawCircleV(menuChoice, radiusMenu, YELLOW);
	DrawText("GRADIUS", 550, 100, 50, MAROON);
	DrawText("Play", 600, 300, 50, menuColor);
	DrawText("Credits", 560, 400, 50, creditsColor);
	EndDrawing();
}
