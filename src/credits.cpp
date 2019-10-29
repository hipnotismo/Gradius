#include "credits.h"
#include "game.h"

#include "raylib.h"

void cred::updateCredits()
{
	if (IsKeyPressed(KEY_ENTER))
		state = mainMenu;
}
void cred::drawCredits()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Press enter to return to main menu", 200, 600, 50, GREEN);
	EndDrawing();
}