#ifndef FRIENDLY_MISSILE_h
#define FRIENDLY_MISSILE_h

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game_object.h"
#include "point.h"
#include "aabb.h"
#include "missile.h"
#include "marker.h"
#include <vector>
#include <map>
#include "sprite.h"

class Friendly_missile : public Missile
{
	public:
		Friendly_missile(std::string, Point, SDL_Renderer*,
				Point, int, std::map<int, std::vector<Game_object*>>, Marker*);
		void update();
		void explode();
		void check_boundaries();
	private:
		std::map<int, std::vector<Game_object*>> m;
		Marker* marker;
		Sprite sprite;
		//int timer;
};


#endif


