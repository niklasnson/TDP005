#include <iostream>
#include "rotatable.h"
#include "point.h"

using namespace std;

Rotatable::Rotatable(std::string f, Point p, SDL_Renderer* r, Point t):Collisionable(f, p, r), target{t}{}

void Rotatable::update()
{
	//update shit
}

double Rotatable::calculate_allignment()
{
	//do necessary calculation to rotate object correctly
	return 36.5 //rotate takes double in sdl
}

Point Rotatable::get_target()
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

void Rotatable::set_angle(value)
{
	angel = value; 
}
