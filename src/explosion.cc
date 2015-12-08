#include "collisionable.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.h"
#include <string>
#include <vector>
#include <map>
#include "explosion.h"

using namespace std;

Explosion::Explosion(std::string f, Point p, SDL_Renderer* r, map<int, vector<Game_object*>> m):Collisionable(f, p, r),m{m}, sprite{f, r, 15, 42, 15}{}


void Explosion::update()
{
	sprite.draw(get_point());
}
