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
#include <random>
#include <vector>
#include <map>
#include "sprite.h"

using namespace std;

Friendly_missile::Friendly_missile(std::string f, Point p, SDL_Renderer* r, 
		Point t, int s, map<int, vector<Game_object*>> m, Marker* mark):
	Missile(f, p, r, t, s), m{m}, marker{mark},sprite{f, r, 15, 42, 15}
	{
	}//, timer{0}{}

bool reached_target(Point a, Point b)
{
	/*if (a.x == b.x && a.y == b.y)
		{return true;}

	if ((a.x > b.x && a.x < b.x+10) && (a.y > b.y && a.y < b.x+10))
		{return true;}

	if ((a.x < b.x && a.x > b.x+10) && (a.y < b.y && a.y > b.x+10))
		{return true;}
		*/

	return b.x-3 <= a.x+3 && b.x+3 >= a.x-3 
				&& b.y-3 <= a.y+3 && b.y+3 >= a.y-3;

	return false;
}

void Friendly_missile::update()
{
	//check collision transform etc
	//if (!is_destroyed())
	//{	
		if (get_state())
		{
			move();
			check_boundaries();
			if (reached_target(get_point(), get_target()))
			{
				//cout << "destroyed marker" << endl;
				marker -> destroy();
				explode();
			}
		}
		/*else
		{
			++ timer;
			if (timer > 100)
			{
				destroy();
				cout << "destroy" << endl;
			}	
		}*/
		sprite.draw(get_point(), angle);
		//sprite -> draw(angle);
	//}
	
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


