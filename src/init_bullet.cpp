#include "init_bullet.h"

#include "raylib.h"

float radius = 5.0f;

Bullet::Bullet(float x, float y, float speed)
{
	_x = x;
	_y = y;
	_speed = speed;
	shooted = false;
}
Bullet::~Bullet() {}
void Bullet::setX(float x)
{
	_x = x;
}
void Bullet::setY(float y)
{
	_y = y;
}
float Bullet::getX()
{
	return _x;
}
float Bullet::getY()
{
	return _y;
}
void Bullet::createBullet()
{
	ball.x = _x;
	ball.y = _y;
	DrawCircleV(ball, radius, MAROON);
}
void Bullet::setSpeed(float speed) 
{
	_speed = speed;
}
float Bullet::getSpeed()
{
	return _speed;
}
void Bullet::moveShoot()
{
	_x += _speed * GetFrameTime();
}
void Bullet::shoot()
{
	shooted = true;
}