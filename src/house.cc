#include "house.h"
House::House(
	std::string filename, 
	Point point, 
	SDL_Renderer* renderer, 
	int sprite_width, 
	int sprite_height, 
	int sprite_speed):Game_object(filename, point, 
		renderer, sprite_width, sprite_height, sprite_speed)
{
	intact = true;
}

void House::update()
{
	draw();
}

bool House::get_state()
{
	return intact;
}

void House::set_state(bool state) 
{
	intact = state; 
}
