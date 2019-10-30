#ifndef INIT_ENEMY2_H
#define INIT_ENEMY2_H
#include "raylib.h"

class Enemy2
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
	Enemy2(float x, float y, float width, float height, float speedX, float speedY, bool state);
	~Enemy2();
	void setX2(float x);
	float getX2();
	void setY2(float y);
	float getY2();
	void setState2(bool state);
	bool getState2();
	void initEnemy2();
	void movement2();
};
#endif // !INIT_ENEMY_H


