#include "static.h"

Static::Static(std::string i, Point crd, SDL_Renderer* r, int sW, int sH, int sS):Game_object(i, crd, r, sW, sH, sS){}

void Static::update()
{
	draw();
}
