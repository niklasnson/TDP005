#include <iostream>
#include "rotatable.h"
#include "point.h"

using namespace std;

Rotatable::Rotatable():{}

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
