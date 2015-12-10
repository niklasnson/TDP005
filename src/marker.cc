#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "static.h"
#include "point.h"
#include "marker.h"

Marker::Marker(std::string i, 
								Point crd, 
								SDL_Renderer* r, 
								int sW, 
								int sH, 
								int sS
							):Static(i, crd, r, sW, sH, sS){}

void Marker::update()
{
	draw();
}
