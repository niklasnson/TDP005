#include "static.h"

Static::Static(
   SDL_Texture* texture, 
   Point point, 
   SDL_Renderer* renderer, 
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Game_object(texture, point, renderer, 
					sprite_width, sprite_height, sprite_speed)
{}

void Static::update()
{
   draw();
}
