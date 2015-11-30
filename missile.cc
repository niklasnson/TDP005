#include <iostream>
#include "missile.h"

using namespace std;

Missile::Missile():{}

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
