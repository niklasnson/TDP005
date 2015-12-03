#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "static.h"
#include "screen_dimensions.h"
#include "point.h"
#include "marker.h"


Marker::Marker(std::string i, Point crd, SDL_Renderer* r, int f):Static(i, crd, r), frame{f}{}

void Marker::update()
{
	draw(frame);
	if (frame < 6)
	{
		frame = frame + 1;
	}
	else 
	{
		frame = 0;
	}

}

void Marker::set_frame(int)
{

}

int Marker::get_frame()
{
	return frame;
}
