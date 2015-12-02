#include <iostream>
#include "missile.h"

using namespace std;

Missile::Missile(std:string f, Point p, SDL_Renderer* r, Point t, Point s):Rotatable(f, p, r, t), speed{s}{}

void Missile::update()
{
	//do everyting that needs to be done to update, think simulate
}

Point Missile::get_speed()
{
	return speed;
}

void Missile::set_speed(Point spd)
{
	speed = spd;
}

bool Missile::get_state()
{
		return is_missile;
}

void Missile::set_state(bool st);
{
	is_missile = st;
}
