#include "init_enemy.h"
static int limitPosY = 600;
static int limitNegY = 50;

Enemy::Enemy(float x, float y, float width, float height, float speedX, float speedY, bool state)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_speedX = speedX;
	_speedY = speedY;
	_state = state;
}
Enemy::~Enemy()
{

}
void Enemy::setState(bool state)
{
	_state = state;
}
bool Enemy::getState() 
{
	return _state;
}
void Enemy::initEnemy()
{
	_enemy.x = _x;
	_enemy.y = _y;
	_enemy.width = _width;
	_enemy.height = _height;
	DrawRectangleRec(_enemy, DARKBLUE);
}
void Enemy::movement()
{
		_x -= _speedX * GetFrameTime();
		_y -= _speedY * GetFrameTime();
		if (_y <= limitNegY)
			_speedY *= -1.0f;
		else if (_y >= limitPosY)
			_speedY *= -1.0f;
}