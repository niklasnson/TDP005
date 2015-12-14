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

class Enemy_missile : public Missile
{
public:
	Enemy_missile(std::string, 
								SDL_Renderer*, 
								int,
								std::map<int, std::vector<Game_object*>> &,
								int, 
								int, 
								int
								); 

	void update();
	void check_boundaries();
	bool reached_target(Point, Point);
	void explode();
	bool get_hit_house();
	void set_hit_house(bool);
private:
	int timer;
	bool hit_house;
};
#endif
