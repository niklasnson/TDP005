#include "static.h"

Static::Static(
	std::string const& filename, 
	Point point, 
	SDL_Renderer* renderer, 
	int const& sprite_width, 
	int const& sprite_height, 
	int const& sprite_speed):Game_object(filename, point, renderer, 
		sprite_width, sprite_height, sprite_speed)
{}

void Static::update()
{
	draw();
}
