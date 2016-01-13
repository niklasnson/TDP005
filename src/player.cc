#include "player.h"
Player::Player(
   SDL_Texture* texture, 
   Point point, 
   SDL_Renderer* renderer, 
   Point target, 
   int const& sprite_width, 
   int const& sprite_height, 
   int const& sprite_speed):Rotatable(texture, point, 
				      renderer, target, sprite_width, sprite_height, sprite_speed)
{}

/// Checks how many degrees to rotate the draws it
void Player::update()
{
   int x;
   int y;
   SDL_GetMouseState(&x ,&y);
   Point a{x, y};
   set_target(a);
   calculate_allignment();
   sprite.draw(get_point(), angle);
}
