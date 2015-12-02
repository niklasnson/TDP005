#include "marker.h"

Marker::Marker(std::string i, Point crd, SDL_Renderer* r):Static(i, crd, r){}

void Marker::update()
{
	draw();
}
