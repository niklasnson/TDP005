#include "powerup.h"
Powerup::Powerup(
   Texture textures,
   SDL_Texture* texture,
   SDL_Renderer* renderer,
   int speed,
   std::map<int, std::vector<Game_object*>> & game_objects, 
   bool & powerup, 
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Missile(textures, texture, get_random_spawn(),
				    renderer, get_random_target(),speed, game_objects, sprite_width,
				    sprite_height, sprite_speed)
{}

//! Update the object.
void Powerup::update()
{
   if (get_state())
   {
      move();
      check_boundaries();
      draw(angle);
   }
}

//! Check if outside screen.
void Powerup::check_boundaries()
{
   if (get_point().y > Variables::screen_height || 
       get_point().y < 0 || 
       get_point().x > Variables::screen_width || 
       get_point().x <0)
   {destroy();}
}

//! Get a random spawn point. 
Point Powerup::get_random_spawn() const
{
   std::random_device rd;
   std::mt19937 gen(rd());
   int x;
   int y;
   std::uniform_int_distribution<int> dis(100, 1000);
	
   x = dis(gen);
   y = 1;

   Point p{x, y};
   return p;
}

//! Select a random target. 
Point Powerup::get_random_target() const
{
   std::random_device rd;
   std::mt19937 gen(rd());
   int x;
   int y;
   std::uniform_int_distribution<int> dis(100, 1000);
	
   x = dis(gen);
   y = Variables::screen_height;

   Point p{x, y};
   return p;
}

