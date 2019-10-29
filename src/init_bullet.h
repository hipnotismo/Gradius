#ifndef INIT_BULLET_H
#define INIT_BULLET_H
#include "init_player.h"

extern float radius;

class Bullet 
{
private:
	float _x;
	float _y;
	float _speed;
public:
	Vector2 ball;
	bool shooted;
	Bullet(float x, float y, float speed);
	~Bullet();
	void setX(float x);
	void setY(float x);
	float getX();
	float getY();
	void createBullet();
	void setSpeed(float speed);
	float getSpeed();
	void moveShoot();
	void shoot();
};
#endif // !INIT_BULLET_H

