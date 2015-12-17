#include "marker.h"
Marker::Marker(
	std::string filename, 
	Point point, 
	SDL_Renderer* renderer, 
	int sprite_width, 
	int sprite_height, 
	int sprite_speed):Static(filename, point, renderer, 
		sprite_width, sprite_height, sprite_speed)
{}

//just draws the marker on screen
void Marker::update()
{
	draw();
}
