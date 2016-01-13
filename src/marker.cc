#include "marker.h"
Marker::Marker(
   SDL_Texture* texture, 
   Point point, 
   SDL_Renderer* renderer, 
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Static(texture, point, renderer, 
				   sprite_width, sprite_height, sprite_speed)
{}

/// Just draws the marker on screen.
void Marker::update()
{
   draw();
}
