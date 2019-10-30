#include "init_enemy2.h"
static int limitPosY = 600;
static int limitNegY = 50;

Enemy2::Enemy2(float x, float y, float width, float height, float speedX, float speedY, bool state)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_speedX = speedX;
	_speedY = speedY;
	_state = state;
}
Enemy2::~Enemy2()
{

}
void Enemy2::setX2(float x)
{
	_x = x;
}
float Enemy2::getX2()
{
	return _x;
}
void Enemy2::setY2(float y)
{
	_y = y;
}
float Enemy2::getY2()
{
	return _y;
}
void Enemy2::setState2(bool state)
{
	_state = state;
}
bool Enemy2::getState2()
{
	return _state;
}
void Enemy2::initEnemy2()
{
	_enemy.x = _x;
	_enemy.y = _y;
	_enemy.width = _width;
	_enemy.height = _height;
	DrawRectangleRec(_enemy, MAROON);
}
void Enemy2::movement2()
{
	_x -= _speedX * GetFrameTime();
	if (_y <= limitNegY)
		_speedY *= -1.0f;
	else if (_y >= limitPosY)
		_speedY *= -1.0f;
}