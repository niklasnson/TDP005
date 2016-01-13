#include "rotatable.h"
Rotatable::Rotatable(
   SDL_Texture* texture, 
   Point point, 
   SDL_Renderer* renderer, 
   Point target, 
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Game_object(texture, point, renderer,
					sprite_width, sprite_height, sprite_speed),
			    target{target}
{
   calculate_allignment();
}

/// calc number of degrees to rotate texture.
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

/// returns the target the object has.
Point Rotatable::get_target() const
{
   return target; 
}

/// set the target the object has.
void Rotatable::set_target(Point const& targ)
{
   target = targ;
}

/// set the angle the object has. 
double Rotatable::get_angle() const
{
   return angle;
}

/// set the angle the object has.  
void Rotatable::set_angle(double const& value)
{
   angle = value; 
}
