#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "point.h"
#include "house.h"
#include <iostream>
House::House(std::string i, 
							Point crd, 
							SDL_Renderer* r, 
							int sW, 
							int sH, 
							int sS):Game_object(i, crd, r, sW, sH, sS)
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
