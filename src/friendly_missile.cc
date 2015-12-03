#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <iostream>
#include "screen_dimensions.h"
#include "point.h"
#include "aabb.h"
#include "friendly_missile.h"
#include <random>

using namespace std;

Friendly_missile::Friendly_missile(std::string f, Point p, SDL_Renderer* r, Point t, int s):
	Missile(f, p, r, t, s){}


void Friendly_missile::update()
{
	//check collision transform etc
	if (get_state())
	{
		move();
		check_boundaries();
		draw(angle);
	}
	//else
	//set speed 0
	//etc
}

void Friendly_missile::explode()
{
	set_state(false);
	set_speed(0);
	set_move(0, 0);
}

void Friendly_missile::check_boundaries()
{
	Screen_dimensions sd;
	if (get_point().y > sd.SCREEN_H || 
			get_point().y < 0 || 
			get_point().x > sd.SCREEN_W || 
			get_point().x <0)
	{destroy();}
}


