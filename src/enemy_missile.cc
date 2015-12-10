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
#include "explosion.h"

using namespace std;

Enemy_missile::Enemy_missile(
			std::string i, 
			SDL_Renderer* r, 
			int s, 
			map<int, vector<Game_object*>> & m, 
			int sW, 
			int sH, 
			int sS): Missile(i, r, s, m, sW, sH, sS), timer{0}{}

void Enemy_missile::update()
{
	if (get_state())
	{
		move();
		check_boundaries();
		draw(get_angle());
		if( reached_target(get_point(), get_target()) )
		{	
			explode();
		}
	}

}

void Enemy_missile::check_boundaries()
{
	Screen_dimensions sd;
	if (get_point().y > sd.SCREEN_H || 
			get_point().y < 0 || 
			get_point().x > sd.SCREEN_W || 
			get_point().x <0)
		{
			destroy();
		}
}

bool Enemy_missile::reached_target(Point a, Point b)
{
	return b.x-1 <= a.x+1 && b.x+1 >= a.x-1 
				&& b.y-1 <= a.y+1 && b.y+1 >= a.y-1;

}

void Enemy_missile::explode()
{
	Point housepos{0, 0};
	for (auto go : m[1])
	{
		if (go -> get_point().x <= (get_point().x)+60 && (go -> get_point().x)+60 >= get_point().x 
         && go->get_point().y <= (get_point().y)+10 && (go->get_point().y)+10 >= get_point().y)
		{
			//cout << "before" << endl;
			housepos.x = go->get_point().x;
			housepos.y = go->get_point().y;
			dynamic_cast<House*>(go) -> destroy();
			//cout << "HOUSESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" << endl;
		}

	}
	House* newhouse{new House{"sprites/house_d.png", housepos, renderer, 96, 96, 0}};
	newhouse -> set_state(false);
	m[1].push_back(newhouse);

	//cout << "before" << endl;
	set_state(false);
	set_speed(0);
	set_move(0, 0);
	Point explosion_point{get_point().x - 70, get_point().y - 44};
	bool powerup;
	m[5].push_back(new Explosion{"sprites/scaledgexplosion.png", explosion_point, get_renderer(), m, &powerup, 185, 222, 8});
	destroy();

}



