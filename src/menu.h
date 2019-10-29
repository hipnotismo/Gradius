#ifndef MENU_H
#define MENU_H
#include "raylib.h"
extern Rectangle menuSel;
extern Vector2 menuChoice;
namespace menu 
{
void updateMenu();
void drawMenu();
}
#endif // !MENU_H