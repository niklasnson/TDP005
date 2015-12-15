#include "player.h"
Player::Player(
	std::string filename, 
	Point point, 
	SDL_Renderer* renderer, 
	Point target, 
	int sprite_width, 
	int sprite_height, 
	int sprite_speed):Rotatable(filename, point, 
		renderer, target, sprite_width, sprite_height, sprite_speed)
{}

void Player::update()
{
	int x;
	int y;
	SDL_GetMouseState(&x ,&y);
	Point a{x, y};
	set_target(a);
	calculate_allignment();
	sprite.draw(get_point(), angle);
}
