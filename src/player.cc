#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

//#include "aabb.h"
#include "player.h"
#include "point.h"


Player::Player(std::string f, Point p, SDL_Renderer* r, Point t, int sW, int sH, int sS):
	Rotatable(f, p, r, t, sW, sH, sS){}

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
