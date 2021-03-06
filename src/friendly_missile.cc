#include "friendly_missile.h"

Friendly_missile::Friendly_missile( 
   Texture textures,
   SDL_Texture* texture, 
   Point point,
   SDL_Renderer* renderer, 
   Point target, 
   int speed, 
   std::map<int, std::vector<Game_object*>> & game_objects, 
   Marker * marker,
   bool* powerup,
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Missile(textures, texture, point, renderer, 
				    target, speed, game_objects, sprite_width, 
				    sprite_height, sprite_speed),
			    marker{marker},
   powerup{powerup}
{}

/// Check if missile reached target.
bool Friendly_missile::reached_target(Point a, Point b)
{
   return b.x-3 <= a.x+3 && b.x+3 >= a.x-3 
      && b.y-3 <= a.y+3 && b.y+3 >= a.y-3;
}

/// Moves misille, does checks, draws missile.
void Friendly_missile::update()
{
   if (get_state())
   {
      move();
      check_boundaries();
      if (reached_target(get_point(), get_target()))
      {
	 marker -> destroy();
	 explode();
      }
   }
   draw(get_angle());
}

/// Removes missile, creates a new explosion.
void Friendly_missile::explode()
{
   set_state(false);
   set_speed(0);
   set_move(0, 0);
   Point explosion_point{get_point().x - 44, get_point().y - 44};
   m[5].push_back(new Explosion{textures.get_texture("sprites/explosion.png"), explosion_point, get_renderer(), m, powerup, 96, 96, 10});
   destroy();
}

/// Checks if missile is outside the screen.
void Friendly_missile::check_boundaries()
{
   if (get_point().y > Variables::screen_height || 
       get_point().y < 0 || 
       get_point().x > Variables::screen_width || 
       get_point().x <0)
   {destroy();}
}
