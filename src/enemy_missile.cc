#include "enemy_missile.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <iostream>
#include "screen_dimensions.h"
#include "point.h"
#include "aabb.h"
#include <random>
#include <map>
#include <vector>
#include "house.h"
#include "sprite.h"

using namespace std;

Enemy_missile::Enemy_missile(
			std::string i, 
			SDL_Renderer* r, 
			int s, 
			map<int, vector<Game_object*>> & m, 
			int sW, 
			int sH, 
			int sS): Missile(i, r, s, m, sW, sH, sS){}

void Enemy_missile::update()
{
	if (get_state())
	{
		move();
		check_boundaries();
		draw(get_angle());
	}
}

void Enemy_missile::check_boundaries()
{
	Screen_dimensions sd;
	if (get_point().y > sd.SCREEN_H || 
			get_point().y < 0 || 
			get_point().x > sd.SCREEN_W || 
			get_point().x <0)
		{destroy();}
}

