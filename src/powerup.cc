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
#include "powerup.h"

using namespace std;


Powerup::Powerup(
		std::string f,
		SDL_Renderer* r,
		int s,
		map<int, vector<Game_object*>> & m, 
		bool & p):
	Missile(f, get_random_spawn(),r,get_random_target(),s,m),sprite{f, r, 15, 42, 15}
{
	cout << "POWERUP" << endl;
}

void Powerup::update()
{
	//check collision, transform, destroy building etc.
	if (get_state())
	{
		move();
		check_boundaries();
		draw(angle);
	}
}

void Powerup::check_boundaries()
{
	Screen_dimensions sd;
	if (get_point().y > sd.SCREEN_H || 
			get_point().y < 0 || 
			get_point().x > sd.SCREEN_W || 
			get_point().x <0)
		{destroy();}
}


Point Powerup::get_random_spawn()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int x;
	int y;
	std::uniform_int_distribution<int> dis(100, 1000);
	
	x = dis(gen);
	y = 1;

	Point p{x, y};
	return p;
}

Point Powerup::get_random_target()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int x;
	int y;
	std::uniform_int_distribution<int> dis(100, 1000);
	
	x = dis(gen);
	y = 800;

	Point p{x, y};
	return p;
}

