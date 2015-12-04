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

using namespace std;


Enemy_missile::Enemy_missile(std::string f, Point p, SDL_Renderer* r, Point t, int s):
		Missile(f, p, r, t, s)
{
//	set_random_target();
//	set_random_spawn();
}

void Enemy_missile::update()
{
	//check collision, transform, destroy building etc.
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

void Enemy_missile::check_boundaries()
{
	Screen_dimensions sd;
	if (get_point().y > sd.SCREEN_H || 
			get_point().y < 0 || 
			get_point().x > sd.SCREEN_W || 
			get_point().x <0)
		{destroy();}
}

Point get_random_target()
{
	Screen_dimensions sd;
	std::random_device rd;
	std::mt19937 gen(rd());
	int x;
	int y;
	std::uniform_int_distribution<int> dis(1, sd.SCREEN_W);
	
	x = dis(gen);
	y = 1130;

	Point targ{x, y};
	return targ;
}
Point get_random_spawn()
{
	Screen_dimensions sd;
	std::random_device rd;
	std::mt19937 gen(rd());
	int x;
	int y;
	std::uniform_int_distribution<int> dis(1, sd.SCREEN_W);
	
	x = dis(gen);
	y = 1;

	Point p{x, y};
	return p;

}

