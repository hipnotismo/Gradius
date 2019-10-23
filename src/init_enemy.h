#ifndef INIT_ENEMY_H
#define INIT_ENEMY_H
#include "raylib.h"

class Enemy
{
private:
	float _x;
	float _y;
	float _width;
	float _height;
	float _speedX;
	float _speedY;
	bool _state;
public:
	Rectangle _enemy;
	Enemy(float x, float y, float width, float height, float speedX, float speedY, bool state);
	~Enemy();
	void setX(float x);
	float getX();
	void setY(float y);
	float getY();
	void setState(bool state);
	bool getState();
	void initEnemy();
	void movement();
};
#endif // !INIT_ENEMY_H

