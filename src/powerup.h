#ifndef POWERUP_h
#define POWERUP_h

#include "variables.h"
#include "missile.h"
#include "point.h"
#include "sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include <vector>

class Powerup : public Missile
{
public:
	Powerup(std::string, SDL_Renderer*, int, 
		std::map<int, std::vector<Game_object*>> &, bool &, int, int, int);
	void update();
	void check_boundaries();
	Point get_random_target();

private:
	Point get_random_spawn();
};
#endif
