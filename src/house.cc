#include "house.h"
House::House(
	std::string const& filename, 
	Point point, 
	SDL_Renderer* renderer, 
	int const& sprite_width, 
	int const& sprite_height, 
	int const& sprite_speed):Game_object(filename, point, 
		renderer, sprite_width, sprite_height, sprite_speed)
{
	intact = true;
}

void House::update()
{
	draw();
}

bool House::get_state() const
{
	return intact;
}

void House::set_state(bool state) 
{
	intact = state; 
}
