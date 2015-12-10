#ifndef EXPLOSION_h 
#define EXPLOSION_h 
#include "collisionable.h"
#include "game_object.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.h"
#include <string>
#include <vector>
#include <map>

class Explosion : public Collisionable
{
public: 
	Explosion(
			std::string,
			Point,
			SDL_Renderer*,
			std::map<int, std::vector<Game_object*>> &,
			bool*,
			int, 
			int, 
			int);
	void update(); 

protected:
	int timer;
	std::map<int, std::vector<Game_object*>> & m;
	bool* powerup;

};

#endif
