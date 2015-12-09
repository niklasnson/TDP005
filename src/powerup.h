#ifndef POWERUP_h
#define POWERUP_h

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include "missile.h"
#include "point.h"
#include "aabb.h"
#include "sprite.h"

class Powerup : public Missile
{
	public:
		Powerup(
				std::string,
				SDL_Renderer*,
				int,
				std::map<int, std::vector<Game_object*>> &,
				bool &);
		void update();
		void check_boundaries();
		Point get_random_target();

	private:
		Point get_random_spawn();
		Sprite sprite;

};

//Point get_random_target();
//Point get_random_spawn();

#endif
