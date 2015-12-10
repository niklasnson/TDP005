#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <iostream>
#include "screen_dimensions.h"
#include "point.h"
#include "aabb.h"
#include "friendly_missile.h"
#include "marker.h"
#include "explosion.h"
#include "game_object.h"
#include <random>
#include <vector>
#include <map>
#include "sprite.h"

using namespace std;

Friendly_missile::Friendly_missile( 
				std::string i, 
				Point p,
				SDL_Renderer* r, 
				Point t, 
				int s, 
				map<int, vector<Game_object*>> & m, 
				Marker * mark,
				bool* po,
				int sW, 
				int sH, 
				int sS):Missile(i, p, r, t, s, m, sW, sH, sS),
				marker{mark},
				powerup{po}{}

bool reached_target(Point a, Point b)
{
	return b.x-3 <= a.x+3 && b.x+3 >= a.x-3 
				&& b.y-3 <= a.y+3 && b.y+3 >= a.y-3;
}

void Friendly_missile::update()
{
	if (get_state())
	{
		move();
		check_boundaries();
		if (reached_target(get_point(), get_target()))
		{
			marker -> destroy();
			explode();
		}
	}
	draw(get_angle());
}

void Friendly_missile::explode()
{
	set_state(false);
	set_speed(0);
	set_move(0, 0);
	Point explosion_point{get_point().x - 44, get_point().y - 44};
	m[5].push_back(new Explosion{"sprites/explosion.png", explosion_point, get_renderer(), m, powerup, 96, 96, 10});
	destroy();
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
