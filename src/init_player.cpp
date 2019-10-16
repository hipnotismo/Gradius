#include "init_player.h"
Player::Player(float x, float y, float width, float height, int lives, int ammo, float speedX, float speedY, bool state)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_lives = lives;
	_ammo = ammo;
	_speedX = speedX;
	_speedY = speedY;
	_state = state;
}
Player::~Player() 
{
	BeginDrawing();
	DrawText("You're Dead", 640, 360, 60, GREEN);
	EndDrawing();
}
void Player::setLives(int lives)
{
	_lives = lives;
}
int Player::getLives() 
{
	return _lives;
}
void Player::setAmmo(int ammo)
{
	_ammo = ammo;
}
int Player::getAmmo()
{
	return _ammo;
}
void Player::setState(bool state)
{
	_state = state;
}
bool Player::getState()
{
	return _state;
}
void Player::setPlayer() 
{
	_player.x = _x;
	_player.y = _y;
	_player.width = _width;
	_player.height = _height;
	DrawRectangleRec(_player, DARKBLUE);
}
void Player::input()
{
	if (IsKeyDown(KEY_D))
	{
		_x += _speedX*GetFrameTime();
	}
	if (IsKeyDown(KEY_A))
	{
		_x -= _speedX * GetFrameTime();
	}
	if (IsKeyDown(KEY_S))
	{
		_y += _speedY * GetFrameTime();
	}
	if (IsKeyDown(KEY_W))
	{
		_y -= _speedY * GetFrameTime();
	}
}