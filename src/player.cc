#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

//#include "aabb.h"
#include "player.h"
#include "point.h"


Player::Player(std::string f, Point p, SDL_Renderer* r, Point t):
	Rotatable(f, p, r, t){}

void Player::update()
{
	int x;
	int y;
	SDL_GetMouseState(&x ,&y);
	Point a{x, y};
	set_target(a);
	calculate_allignment();
	draw(angle);
}
