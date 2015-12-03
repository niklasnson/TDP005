#ifndef FRIENDLY_MISSILE_h
#define FRIENDLY_MISSILE_h

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "point.h"
#include "aabb.h"
#include "missile.h"


class Friendly_missile : public Missile
{
	public:
		Friendly_missile(std::string, Point, SDL_Renderer*, Point, int);
		void update();
		void explode();
};


#endif
