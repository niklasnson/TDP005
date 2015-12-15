#ifndef MARKER_h 
#define MARKER_h
#include "point.h"
#include "static.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Marker : public Static 
{
public:
	Marker(std::string, Point, SDL_Renderer*, int, int, int);
	void update();
};
#endif
