#include "static.h"

Static::Static(std::string i, Point crd, SDL_Renderer* r):
Game_object(i, crd, r){}

void Static::update()
{
	draw();
}
