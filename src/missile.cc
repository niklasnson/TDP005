
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <iostream>

#include "point.h"
#include "aabb.h"
#include "missile.h"

using namespace std;

Missile::Missile(std::string f, Point p, SDL_Renderer* r, Point t, int s):
		Rotatable(f, p, r, t), speed{s}, is_missile{true}, 
		curr_x{static_cast<double>(get_point().x)}, curr_y{static_cast<double>(get_point().y)},
		move_x{0}, move_y{0}
{	
	calculate_allignment();
	double delta_x{static_cast<double>(cords.x - target.x)};
	double delta_y{static_cast<double>(cords.y - target.x)};
	double greatest_delta{delta_y};


	if (abs(delta_x) > abs(delta_y))
		greatest_delta = delta_x;
	

	move_x = delta_x/greatest_delta;
	move_y = delta_y/greatest_delta;
}


void Missile::update()
{	
	curr_x += (move_x * speed);
	curr_y += (move_y * speed);
	Point new_location{static_cast<int>(curr_x + 0.5), static_cast<int>(curr_y + 0.5)};
	set_point(new_location);
	draw(angle);
	//do everyting that needs to be done to update, think simulate
}

int Missile::get_speed()
{
	return speed;
}

void Missile::set_speed(int const& spd)
{
	speed = spd;
}

bool Missile::get_state()
{
		return is_missile;
}

void Missile::set_state(bool st)
{
	is_missile = st;
}
