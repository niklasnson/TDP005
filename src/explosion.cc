#include "explosion.h"

Explosion::Explosion(
   SDL_Texture* texture,
   Point point,
   SDL_Renderer* renderer,
   std::map<int, std::vector<Game_object*>> & game_objects,
   bool* powerup,
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Game_object(texture, point, renderer, 
					sprite_width, sprite_height, sprite_speed), 
			    timer{0}, 
   m(game_objects), 
   powerup{powerup} 
{}

//! Explosion checks collision against enemy missiles and powerups.
void Explosion::update()
{
   sprite.draw(get_point());
   timer += 1;
	
   for (auto go : m[3])
   {
      if (go -> get_point().x <= (get_point().x)+60 && (go -> get_point().x)+42 >= get_point().x 
	  && go->get_point().y <= (get_point().y)+60 && (go->get_point().y)+69 >= get_point().y)
      {
	 go -> destroy();
	 if(dynamic_cast<Powerup*>(go) != nullptr)
	 {
	    *powerup = true;
	 }
      }
   }

   if (timer > 40)
   {
      destroy();
   }
}
