#include "static.h"

Static::Static(
	std::string filename, 
	Point point, 
	SDL_Renderer* renderer, 
	int sprite_width, 
	int sprite_height, 
	int sprite_speed):Game_object(filename, point, renderer, 
		sprite_width, sprite_height, sprite_speed)
{}

void Static::update()
{
	draw();
}
