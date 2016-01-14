#include "missile.h"
Missile::Missile(
   Texture textures,
   SDL_Texture* texture, 
   Point point,
   SDL_Renderer* renderer, 
   Point target,
   int speed, 
   std::map<int, std::vector<Game_object*>> &game_objects, 
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Rotatable(texture, point, renderer, 
				      target, sprite_width, sprite_height, sprite_speed),
			    textures{textures},
   speed{speed},
   is_missile{true},
   curr_x{static_cast<double>(get_point().x)},
   curr_y{static_cast<double>(get_point().y)},
   move_x{0},
   move_y{0},
   m(game_objects)
   {
      calculate_allignment();

      //calculation to decide how much the missile should move each update
      double delta_x{static_cast<double>(target.x-cords.x)};
      double delta_y{static_cast<double>(target.y-cords.y)};
      double greatest_delta{std::abs(delta_y)};
      if (abs(delta_x) > abs(delta_y))
	 greatest_delta = abs(delta_x);
      set_move(delta_x/greatest_delta, delta_y/greatest_delta);
   }

Missile::Missile(
   Texture textures,
   SDL_Texture* texture, 
   SDL_Renderer* renderer, 
   int speed, 
   std::map<int, std::vector<Game_object*>> &game_objects, 
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Rotatable(texture, get_random_spawn(), 
				      renderer, Point{0,0}, sprite_width, sprite_height, sprite_speed),
   textures{textures},			    
speed{speed}, 
   is_missile{true},
   curr_x{static_cast<double>(get_point().x)},
   curr_y{static_cast<double>(get_point().y)},
   move_x{0},
   move_y{0},
   m(game_objects)
   {
      set_target(get_random_target());
      calculate_allignment();
      double delta_x{static_cast<double>(target.x-cords.x)};
      double delta_y{static_cast<double>(target.y-cords.y)};
      double greatest_delta{std::abs(delta_y)};
      if (abs(delta_x) > abs(delta_y))
	 greatest_delta = abs(delta_x);
      set_move(delta_x/greatest_delta, delta_y/greatest_delta);
   }

//! Get random target.
Point Missile::get_random_target() const
{
   bool done{false};
   Point target;

   while (!done)
   {
      done=false;
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<int> dis(0, 5);
      if(dynamic_cast<House*>(m[1].at(dis(rd))) -> get_state())
      {
	 target.x = m[1].at(dis(gen)) -> get_point().x; //16 half house width
	 target.y = m[1].at(dis(gen)) -> get_point().y; //16 half house width
	 done=true;
      }
   }
   target.x += 16;
   return target;
}

//! Get a random spawn point. 
Point Missile::get_random_spawn() const
{
   std::random_device rd;
   std::mt19937 gen(rd());
   int x;
   int y;
   std::uniform_int_distribution<int> dis(1, Variables::screen_width);
	
   x = dis(gen);
   y = 1;

   Point p{x, y};
   return p;
}

//! Move missile to new location.
void Missile::move()
{
   curr_x += (move_x * speed);
   curr_y += (move_y * speed);
   Point new_location{static_cast<int>(curr_x + 0.5), static_cast<int>(curr_y + 0.5)};
   set_point(new_location);

}

//! Return current speed. 
int Missile::get_speed() const
{
   return speed;
}

//! Set new speed. 
void Missile::set_speed(int const& spd)
{
   speed = spd;
}

//! Set move.
void Missile::set_move(double const& x, double const& y)
{
   move_x = x;
   move_y = y;
}
//! Set move.
void Missile::set_move(Point const& a)
{
   move_x = a.x;
   move_y = a.y;
}

//! Get state of missile.
bool Missile::get_state() const
{
   return is_missile;
}
//! Set state of missile.
void Missile::set_state(bool const& st)
{
   is_missile = st;
}

