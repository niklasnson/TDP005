#include "rotatable.h"
Rotatable::Rotatable(
	std::string filename, 
	Point point, 
	SDL_Renderer* renderer, 
	Point target, 
	int sprite_width, 
	int sprite_height, 
	int sprite_speed):Game_object(filename, point, renderer,
		sprite_width, sprite_height, sprite_speed),
	target{target}
{
	calculate_allignment();
}

void Rotatable::calculate_allignment()
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
	set_angle(v_deg + 270);
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
