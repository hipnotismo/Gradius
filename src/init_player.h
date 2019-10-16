#ifndef INIT_H
#define INIT_H
#include "raylib.h"
class Player 
{
private:
	float _x;
	float _y;
	float _width;
	float _height;
	int _lives;
	int _ammo;
	float _speedX;
	float _speedY;
	bool _state;
public:
	Rectangle _player;
	Player(float x, float y, float width, float height, int lives, int ammo, float speedX, float speedY, bool state);
	~Player();
	void setLives(int lives);
	int getLives();
	void setAmmo(int ammo);
	int getAmmo();
	void setState(bool state);
	bool getState();
	void setPlayer();
	void input();
};
#endif // !INIT_H

