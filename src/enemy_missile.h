#ifndef ENEMYMISSILE_h
#define ENEMYMISSILE_h

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

class Enemy_missile : public Missile
{
	public:
		Enemy_missile(
				std::string,
				SDL_Renderer*,
				int,
				Point,
				std::map<int, std::vector<Game_object*>> &);
		void update();
		void check_boundaries();

	private:
		Point get_random_target();
		Point get_random_spawn();

};

//Point get_random_target();
//Point get_random_spawn();

#endif
