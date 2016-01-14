#include "house.h"


House::House(
   SDL_Texture* texture, 
   Point point, 
   SDL_Renderer* renderer, 
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Game_object(texture, point, 
					renderer, sprite_width, sprite_height, sprite_speed)
{
   intact = true;
}

//! Update the house object.
void House::update()
{
   draw();
}

//! Return the state of the house. 
bool House::get_state() const
{
   return intact;
}

//! Set the state of the house. 
void House::set_state(bool state) 
{
   intact = state; 
}
