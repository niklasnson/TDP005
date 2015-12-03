#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "point.h"
#include "house.h"

House::House(std::string f, Point p, SDL_Renderer* r):Collisionable(f, p, r)
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
