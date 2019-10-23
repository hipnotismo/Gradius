#ifndef GAME_H
#define GAME_H
#include "gameplay.h"
enum GameState
{
	mainMenu,
	controls,
	gameplay, 
	gameOver,
	Credits
};
extern GameState state;
namespace game 
{
void init();
void update();
void draw();
void deInit();
void executeGame();
}
#endif // !GAME_H
