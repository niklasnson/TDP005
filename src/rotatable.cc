#include <iostream>
#include "rotatable.h"
#include "point.h"
#include <cmath>
#include <string>

using namespace std;

Rotatable::Rotatable(std::string f, Point p, SDL_Renderer* r, Point t):
			Collisionable(f, p, r), target{t}{}

void Rotatable::update()
{
	//update shit
}

double Rotatable::calculate_allignment() const
{
	const double pi{3.1415926535897};
	double delta_x;
	double delta_y;
	double v_rad;
	double v_deg;
	delta_x = cords.x - target.x;
	delta_y = cords.y - target.y;
	v_rad = atan2(delta_y, delta_x);
	v_deg = v_rad * (180.0000 / pi);
	return v_deg;
}

Point Rotatable::get_target() const
{
	return target; //returns the target the object has
}

void Rotatable::set_target(Point const& targ)
{
	target = targ;
}

double Rotatable::get_angle()
{
	return angle;
}

void Rotatable::set_angle(double const& value)
{
	angle = value; 
}
