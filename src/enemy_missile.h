#ifndef ENEMYMISSILE_h
#define ENEMYMISSILE_h
#include "variables.h"
#include "explosion.h"
#include "house.h"
#include "missile.h"
#include "point.h"
#include "sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <map>
#include <string>
#include <vector>

class Enemy_missile : public Missile
{
public:
	Enemy_missile(std::string const&, SDL_Renderer*, int, 
		std::map<int, std::vector<Game_object*>> &, int const&, int const&, int const&); 

	void update();
	void check_boundaries();
	bool reached_target(Point const&, Point const&);
	void explode();
	bool get_hit_house() const;
	void set_hit_house(bool);
private:
	int timer;
	bool hit_house;
};
#endif
